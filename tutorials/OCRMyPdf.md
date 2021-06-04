# OCRMyPDF 的使用- 扫描版 PDF 文字识别并合并入原 PDF

## 介绍

OCRMyPDF 可以将扫描版的 pdf （图片组成）上加一层文字，使得可以复制对应位置的文字

项目地址 [jbarlow83/OCRmyPDF: OCRmyPDF adds an OCR text layer to scanned PDF files, allowing them to be searched](https://github.com/jbarlow83/OCRmyPDF)

官方文档：[Installing OCRmyPDF — ocrmypdf 12.0.2.post9+g3d6907f documentation](https://ocrmypdf.readthedocs.io/en/latest/installation.html)

## Windows Ubuntu 子系统下安装和使用

### 安装 `ocrmypdf`

```shell
apt install ocrmypdf
```

### Installing the JBIG2 encoder(可选)

```shell
sudo apt-get update
sudo apt-get install automake
sudo apt install libtool
```

```shell
git clone https://github.com/agl/jbig2enc
cd jbig2enc
./autogen.sh
./configure && make
sudo make install
```

安装简体中文语言包

```shell
sudo apt-get install tesseract-ocr-chi-sim
```

OCR命令注释

```shell
ocrmypdf -l eng+chi_sim # it supports multiple languages
		--jobs 4 # it uses multiple cores by default
		--output-type pdf# 输出标准pdf 利于减小文件体积
		"唐朔飞-计算机组成原理(第二版).pdf" # 文件输入
		output.pdf # 输出文件名字
```

```shell
ocrmypdf -l eng+chi_sim --jobs 4 --output-type pdf "唐朔飞-计算机组成原理(第二版).pdf" output.pdf
```

## docker下安装和使用

```shell
docker pull jbarlow83/ocrmypdf
```

### Linux 下docker命令

先使用命令别称，可用于简化后面的命令

```shell
alias docker_ocrmypdf='docker run --rm  -i --user "$(id -u):$(id -g)" --workdir /data -v "$PWD:/data" jbarlow83/ocrmypdf'
```

下面命令中的 `/data/不能修改或者省略`（由于docker不允许将主机目录挂载到docker容器的根目录下）

```shell
docker_ocrmypdf --output-type pdf /data/当前目录下的pdf文件名.pdf /data/output.pdf
```

### windows下docker命令

```shell
docker run --rm  -i --workdir /data -v "${PWD}:/data" jbarlow83/ocrmypdf  -l eng+chi_sim --output-type pdf "/data/唐朔飞-计算机组成原理(第二版).pdf" "/data/output.pdf"
```

## 识别效果

- 源pdf文件像素越高识别效果越好
- 纯中文识别比中英文夹杂效果好
- 公式、分式识别不行

## 参考

[jbarlow83/OCRmyPDF: OCRmyPDF adds an OCR text layer to scanned PDF files, allowing them to be searched](https://github.com/jbarlow83/OCRmyPDF)

[Installing OCRmyPDF — ocrmypdf 12.0.2.post9+g3d6907f documentation](https://ocrmypdf.readthedocs.io/en/latest/installation.html)

[software recommendation - How to turn a pdf into a text searchable pdf? - Ask Ubuntu](https://askubuntu.com/questions/473843/how-to-turn-a-pdf-into-a-text-searchable-pdf)

[linux 修复aclocal:not found 未找到此命令._liguangxianbin的博客-CSDN博客](https://blog.csdn.net/liguangxianbin/article/details/79742642)

[本地转换中英文扫描版PDF为可搜索文件 | 湖畔随笔](https://lakesidethinks.com/post/2018/12/ocrmypdf-for-chinese-locally.html)

[扫描版 PDF 文字识别并合并入原 PDF - Bend的博客 | Bend's Blog](https://bend1031.github.io/2019/07/02/%E6%89%AB%E6%8F%8F%E7%89%88-PDF-%E6%96%87%E5%AD%97%E8%AF%86%E5%88%AB%E5%B9%B6%E5%90%88%E5%B9%B6%E5%85%A5%E5%8E%9F-PDF_new/)

[Installing tesseract 4.0 on Ubuntu 16.04 Hocus Pocus](https://orionfoysal.github.io/Installing-Tesseract4.0/)

[cmccambridge/ocrmypdf-auto: Docker container to automate use of OCRmyPDF to process documents.](https://github.com/cmccambridge/ocrmypdf-auto#usage)

[windows下安装的docker挂载window目录到docker容器_ldzm-CSDN博客](https://blog.csdn.net/ldzm_edu/article/details/78251528)