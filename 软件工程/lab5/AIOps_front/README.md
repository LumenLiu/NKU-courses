# 智能运维系统（前端）

## 介绍

智能运维系统——前端部分

## 软件架构

本项目是一个前后端分离的智能运维系统，前端采用Vue+Element-Plus+Echarts，后端采用Django+MySQL+Redis。

* 本系统为一个简单的智能运维系统，主要包括系统用户的登录注册、文件上传、日志文件分析、磁盘数据分析、项目整体情况分析等部分。

* 其中系统用户分为两类，一类是高权限的超级管理员，另一类是低权限的普通管理员，其中普通管理员不具备用户管理功能。

    * 在注册页面默认注册低权限的普通管理员，超级管理员可在用户管理板块中对系统的用户权限进行修改。

* 项目中提供了文件的上传接口，帮助用户上传相应的数据文件。

* 项目将各种数据以可视化的形式呈现，给用户以友好体验。

## 环境配置

```
cnpm i
cnpm run serve
```