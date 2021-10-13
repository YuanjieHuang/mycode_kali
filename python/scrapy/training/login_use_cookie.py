import requests
from lxml import etree
class RenrenLogin(object):
    def __init__(self):
        # 个人主页的url地址
        self.url = 'http://www.renren.com/972496145/profile'
        self.headers = {
            # 将拷贝的cookie值放在此处
            'Cookie':'anonymid=kmol2vxqgd4n0e; depovince=HEB; _r01_=1; ick_login=c577d6c0-0ec3-465a-89d0-9e2b8f23e107; taihe_bi_sdk_uid=0738130d7f4532165841f09abc596215; taihe_bi_sdk_session=6277ea795624ba1eddb2603d7fe45c85; _de=1D29BC9596B9643C92425970B59A3DAE; p=3e6989099ff75de92407b791266376095; first_login_flag=1; ln_uact=18519784236; ln_hurl=http://hdn.xnimg.cn/photos/hdn321/20191017/0945/h_main_El46_9a13000ecbe41986.jpg; t=7f25f8a4d3515786d146143f63d108b25; societyguester=7f25f8a4d3515786d146143f63d108b25; id=972496145; xnsid=9770206d; wpsid=15900539012757; ver=7.0; loginfrom=null; wp_fold=0; jebecookies=59f8dfaf-8416-4dbc-a539-016a7ae1b6c5|||||',
            # 注意，useragent不能改变，否则cookie失效
            'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36'
        }
    def get_html(self):
        html = requests.get(url=self.url,headers=self.headers).text
        self.parse_html(html)
    def parse_html(self,html):
        parse_html = etree.HTML(html)
        r_school = parse_html.xpath('//*[@id="operate_area"]/div[1]/ul/li[1]/span/text()')
        print(r_school)
        r_birthday = parse_html.xpath('//li[@class="birthday"]/span/text()')
        print(r_birthday)
        home_info=parse_html.xpath('//*[@id="operate_area"]/div[1]/ul/li/text()')
        item = {}
        item['hometown'] = home_info[2].strip()
        item['address'] = home_info[3].strip()
        print(item)
if __name__ == '__main__':
    spider = RenrenLogin()
    spider.get_html()