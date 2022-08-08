#include "feedback-interface-adaptor.h"
 

/**
 * @class FeedbackServer
 * @brief FeedbackServer의 틀을 가지고있음
 * 
 */
class FeedbackServer : public org::keti::DBus::Feedback_adaptor,
                   public DBus::IntrospectableAdaptor,
                   public DBus::ObjectAdaptor
{
public:
    FeedbackServer(DBus::Connection * conn);
    virtual ~FeedbackServer();
 
public:
    virtual std::string Level1(const std::string& errMsg);
    virtual std::string Level2(const std::string& errMsg);
    virtual std::string Level3(const std::string& errMsg);
    virtual std::string Level4(const std::string& errMsg);
};


 