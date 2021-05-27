# youtube-dl 下载 Youtube 视频

## 安装

### 安装Python

略

### 安装 youtube-dl

```shell
pip install --upgrade youtube-dl
```

## 使用

使用代理下载播放列表，以`https://www.youtube.com/watch?v=ypMjoidhR0c&list=PLRMOX8QaZK8zZ1uKjEkXnMtXJUA6Mo9xh`为例。

找到 `list=`后面的一串字符，此处为`PLRMOX8QaZK8zZ1uKjEkXnMtXJUA6Mo9xh` 这是该播放列表的id，替换下面命令中的字符串，后面的 `127.0.0.1:1080` 为本地代理的ip和端口号。可在proxy软件中查看

更多的命令行参数自行查看官方文档。

```shell
youtube-dl -i PLRMOX8QaZK8zZ1uKjEkXnMtXJUA6Mo9xh --proxy 127.0.0.1:1080
```

![image-20210528002448119](img/youtube-dl/image-20210528002448119.png)



## 不足

以下为下载截图，可以看到下载部分视频时网络出现了问题，需要后面单独重新下载。

![image-20210528002750501](img/youtube-dl/image-20210528002750501.png)

## 参考

https://stackoverflow.com/questions/48422377/youtube-downloading-a-playlist-youtube-dl

https://github.com/ytdl-org/youtube-dl

