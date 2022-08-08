#!/bin/sh

ip=10.0.6.104
id=root
password=ketilinux
path=/conf/ipmi
# path=/tmp

ssh-keygen -f "/root/.ssh/known_hosts" -R "$ip"
ssh-keyscan -t rsa $ip >>~/.ssh/known_hosts

cd ./feedback-engine
cmake CMakeLists.txt
make -j 30
cp feedback_engine ../
cd ../

echo " overlay copy ..."

# cp $edge ../target_sys/firmware/


echo "scp ..."

sshpass -p $password scp feedback_engine $id@$ip:$path
sshpass -p $password scp feed-back-test.sh $id@$ip:$path
#sshpass -p $password scp -r system.d $id@$ip:/etc/dbus-1/system.d

