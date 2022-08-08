#include "feedback-server.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>
#include <limits.h>
 /**
 * @class FeedbackServer
 * @brief FeedbackServer생성자
 */
FeedbackServer::FeedbackServer(DBus::Connection * conn)
: DBus::ObjectAdaptor(*conn, "/org/keti/DBus/Feedback")
{
    std::cout << "Create Level1Server\n";
}
 /**
 * @class FeedbackServer
 * @brief FeedbackServer소멸자
 */
FeedbackServer::~FeedbackServer()
{
    std::cout << "Destroy Level1Server\n";
}
 /**
 * @class FeedbackServer
 * @brief Level1핸들러
 */
std::string FeedbackServer::Level1(const std::string& errMsg)
{

    return errMsg;
}
/**
 * @class FeedbackServer
 * @brief Level2핸들러
 */
std::string FeedbackServer::Level2(const std::string& errMsg)
{

    return errMsg;
}
/**
 * @class FeedbackServer
 * @brief Level3핸들러
 */
std::string FeedbackServer::Level3(const std::string& errMsg)
{

    return errMsg;
}
/**
 * @class FeedbackServer
 * @brief Level4핸들러
 */
std::string FeedbackServer::Level4(const std::string& errMsg)
{

    return errMsg;
}





