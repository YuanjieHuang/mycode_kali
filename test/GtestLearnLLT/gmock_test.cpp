#include <stdio.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class IFileApi {
public:
    virtual int open(const char* path, int oflag) =0;
    virtual int read(const char* path, char* buffer, int size, int &size_ret) =0;
    virtual int close(int fd) =0;
};

class FileDataLoad {
public:
    FileDataLoad(IFileApi *api) : 
            m_fileApi(api),
            m_szFileData(NULL),         
            m_nDataSize(0){;}

    ~FileDataLoad() {
        if (m_szFileData != NULL) {
            delete [] m_szFileData;
        }
    }

    int LoadData(const char* path, int size) {
        // open file
        int fd = m_fileApi->open(path, 0777);
        if (fd <= 0) {
            // we assume that the fd must be > 0. (In reality it may be equal to 0, here is just for sample)
            return -1;
        }

        m_szFileData = new char[size+1];
        m_szFileData[size] = '\0';
        int size_ret = 0;
        // read file -- Just for sample, ignore the consideration for the parameter 'size'
        int ret = m_fileApi->read(path, m_szFileData, size, size_ret);
        if (ret != 0) {
            delete [] m_szFileData;
            return ret;
        }

        if (size != size_ret) {
            // Ignore why return an error for this case. Just for an example.
            return -1;          
        }

        m_nDataSize = ret;

        // close file
        ret = m_fileApi->close(fd);     

        return ret;
    }

    char *GetFileData() {
        return m_szFileData;
    }

    int GetDataSize() {
        return m_nDataSize;
    }

private:
    IFileApi *m_fileApi;
    char* m_szFileData;
    int m_nDataSize;
};

class MockFileApi : public IFileApi{
public:
//Mock的函数是const类型时，需要使用MOCK_CONST_METHODx系列宏。 
    MOCK_METHOD2(open, int(const char*, int));
    MOCK_METHOD4(read, int(const char*, char*, int, int &));
    MOCK_METHOD1(close, int(int));
};

TEST(FileDataLoadTest, LoadData) {
    MockFileApi *api = new MockFileApi;
    FileDataLoad fileLoad((IFileApi*)api);
    int file_load_size = 100;

    // we expect when call api->open, it always returns 11. And this function is only be called one time.
    EXPECT_CALL(*api, open(::testing::_, ::testing::_))
        .Times(1)   // expect only be called 1 time.
        .WillRepeatedly(::testing::Return(11)); // expect always return 11.

    // we expect when call api->read, it sets the 3rd(0-based) parameter to file_load_size and returns 0. 
    // And this function is only be called one time. 
    EXPECT_CALL(*api, read(::testing::_, ::testing::_, ::testing::_, ::testing::_))//”::testing::_”是一种参数匹配语法，它表示匹配任意类型的参数
        .Times(1)
        .WillRepeatedly(
            ::testing::DoAll(
                ::testing::SetArgReferee<3>(file_load_size),
                ::testing::Return(0)
            )
        );

    // we expect when call api->close, it returns 0. And this function is only be called one time.
    EXPECT_CALL(*api, close(::testing::_))
        .Times(1)
        .WillRepeatedly(::testing::Return(0));

    int ret = fileLoad.LoadData("/home/test_file", file_load_size); 
    // we expect the return value is 0.
    EXPECT_EQ(ret, 0);

    delete api;
}
