## zabbix安装

### 部署

[【保姆级教程-超详细】zabbix 5.0 LTS企业级分布式监控服务搭建、使用及进阶 - 知乎](https://zhuanlan.zhihu.com/p/434879809 )

选择配置生成命令

https://www.zabbix.com/cn/download?zabbix=6.4&os_distribution=ubuntu&os_version=22.04&components=server_frontend_agent&db=mysql&ws=nginx

```shell
wget https://repo.zabbix.com/zabbix/6.4/ubuntu/pool/main/z/zabbix-release/zabbix-release_6.4-1+ubuntu22.04_all.deb
dpkg -i zabbix-release_6.4-1+ubuntu22.04_all.deb
apt update
```



```shell
# 所有节点
rpm -Uvh https://repo.zabbix.com/zabbix/5.0/rhel/7/x86_64/zabbix-release-5.0-1.el7.noarch.rpm
yum clean all
```

```shell
# zabbix-server节点
yum install -y zabbix-server-mysql zabbix-agent centos-release-scl
```

```shell
yum install -y zabbix-web-mysql-scl zabbix-nginx-conf-scl
```

```shell
yum install -y mariadb mariadb-server
```

```shell
systemctl start mariadb
systemctl enable mariadb
```

netsate安装

```
yum install -y net-tools
```



先回车后设置root密码123456

```
mysql_secure_installation
```



```
mysql -uroot -p
```

 密码123456

```
create database zabbix character set utf8 collate utf8_bin;
```

```
create user zabbix@localhost identified by 'zabbix123456';
```

```
grant all privileges on zabbix.* to zabbix@localhost;
```

```
quit;
```

```
zcat /usr/share/doc/zabbix-server-mysql*/create.sql.gz | mysql -uzabbix -p zabbix
```

密码zabbix123456

```
vim /etc/opt/rh/rh-nginx116/nginx/conf.d/zabbix.conf
```



```
rpm -Uvh https://mirror.yandex.ru/centos/7.9.2009/extras/x86_64/Packages/centos-release-scl-rh-2-3.el7.centos.noarch.rpm
```



做到这一步，发现报错

```shell
yum install zabbix-web-mysql-scl zabbix-nginx-conf-scl
```

排查后发现是这没做

[下载Zabbix 5.0 LTS for CentOS 7, MySQL, Nginx](https://www.zabbix.com/cn/download?zabbix=5.0&os_distribution=centos&os_version=7&components=server_frontend_agent&db=mysql&ws=nginx )

编辑配置文件 /etc/yum.repos.d/zabbix.repo and enable zabbix-frontend repository.

```
[zabbix-frontend]...enabled=1...
```



```
vi /etc/opt/rh/rh-nginx116/nginx/conf.d/zabbix.conf
```



```
vi /etc/opt/rh/rh-php72/php-fpm.d/zabbix.conf
```

```
systemctl restart zabbix-server zabbix-agent rh-nginx116-nginx rh-php72-php-fpm
```

```
systemctl enable zabbix-server zabbix-agent rh-nginx116-nginx rh-php72-php-fpm
```





















