#ifndef CustomTypeInterface_h
#define CustomTypeInterface_h

#define SerializeAndDeserialize(className, params)                  \
    void serialize(DataStream &stream, char type) const override    \
    {                                                               \
        InOperator in(stream, type, #className);                    \
        in * params;                                                \
    }                                                               \
                                                                    \
    bool deserialize(DataStream &stream, char type) override  \
    {                                                               \
        OutOperator out(stream, type, #className);                  \
        out * params;                                               \
        return out.isSuccess();                                     \
    } 
    
class CustomTypeInterface
{
public:
    virtual ~CustomTypeInterface() = default;
    virtual void serialize(DataStream &stream, char type) const = 0;
    virtual bool deserialize(DataStream &stream, char type) = 0;
};

#endif
