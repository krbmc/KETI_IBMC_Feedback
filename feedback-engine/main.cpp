#include "handler/feedback-server.h"
#include <future>
#include <sys/types.h>
#include <sys/stat.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <signal.h>  
#include <stdlib.h>

DBus::BusDispatcher dispatcher;

/**
 * @brief D-bus의 데몬화를 위한 작업
 * @details 자식 프로세스 생성 후 부모프로세스를 종료하고, SIGHUP 시그널 무시, 루트 디렉토리로 경로를 변경함
 * @return void
 * 
 */
void demonize(){
  pid_t pid;
  if (( pid = fork()) < 0)exit(0);
  else if(pid != 0) exit(0);  
  signal(SIGHUP, SIG_IGN);
  close(0);
  close(1);
  close(2);
  chdir("/");
  setsid(); 
}

int main()
{
  demonize();
  std::cout<<"start\n";
  DBus::default_dispatcher = &dispatcher;
  std::cout<<"start\n";
  DBus::_init_threading();
  std::cout<<"start\n";
  DBus::Connection conn = DBus::Connection::SystemBus();
  std::cout<<"start\n";
  conn.request_name("org.keti.DBus.Feedback");
  std::cout<<"start\n";

  FeedbackServer server(&conn);
  std::cout<<"start\n";
  std::future<void>fut = std::async(std::launch::async, [=] {
        dispatcher.enter();
  });
  std::cout<<"start\n";
  return 0;
}