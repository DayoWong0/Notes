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

