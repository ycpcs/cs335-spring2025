---
layout: default
course_number: CS335
title: "CTF Setup"
---

### Create a shared key
- Generate a random key: ```date +%s | sha256sum | base64 | head -c 32 ; echo```
  - Using: ```M2ZjODVkZTM5Y2JhODVhNDViNmU2MjM0```

### Juice-Shop
- Azure Container Instances 
- Create as many teams as needed
- Using the cloud shell (Bash)
  ```
  az container create\
    --resource-group ycpcs24-cs335 \
    --name cs335-juice-shop-team5 \
    --image bkimminich/juice-shop \
    --dns-name-label ycpcs24-cs335-team5 \
    --ports 3000 \
    --ip-address public \
    --environment-variables "CTF_KEY=M2ZjODVkZTM5Y2JhODVhNDViNmU2MjM0" "NODE_ENV=ctf"
  ```

### Azure VM:
- Ubuntu 20.04 Server LTS 
- User: ```cs335```
- Connect: ```ssh cs335@52.190.19.87```
  
### Tools 
- Install docker: ```sudo snap install docker```
- Install net-tools: ```sudo apt install net-tools```
  - ```netstat -tulpn | grep LISTEN```
- Install npm: ```sudo apt-get install npm```
- Install n package: ```sudo npm install -g n```
- Update node: ```sudo n latest```
- Setup Docker Compose: ```sudo curl https://desktop.docker.com/linux/main/amd64/145265/docker-desktop-4.29.0-amd64.deb --output docker-desktop-4.29.0-amd64.deb```
  - Not sure if Docker Desktop was needed 
  
### CTFd
- ```git clone https://github.com/CTFd/CTFd.git```
- ```cd CTFd```
- ```pip install -r requirements.txt```
- ```head -c 64 /dev/urandom > .ctfd_secret_key```
- ```sudo apt install python3-pip```
  - Doesn't work: ```pip install -r requirements.txt```
  - Use docker instead: 
    - ```docker compose build```
    - ```docker compose up -d```
- Azure add inbound rule for port 8000 

### Juice Shop CTF CLI
- Install cli package: ```sudo npm install -g juice-shop-ctf-cli```
- ```sudo juice-shop-ctf```
- Copy the challenges locally: ``` scp cs335@52.190.19.87:~/OWASP_Juice_Shop.2024-05-02.CTFd.csv .```
- 
### Obsolete Notes
- Azure add inbound rule for port 3000 
- Pull image: ```sudo docker pull bkimminich/juice-shop```
- Run image to test: ```sudo docker run --rm -p 3000:3000 bkimminich/juice-shop```
  - Test with ip:3000
- ```sudo docker run --rm -d -e "CTF_KEY=M2ZjODVkZTM5Y2JhODVhNDViNmU2MjM0" -e "NODE_ENV=ctf" -p 3000:3000 bkimminich/juice-shop```
- Generate back up: ```sudo juice-shop-ctf```