gcc -DBUF_SIZE=212 stack.c -o stack -g -z execstack -fno-stack-protector
sudo chown root stack
sudo chmod 4755 stack
/bin/ls -l
