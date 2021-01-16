for line in `cat ffile.txt`
do
    # IFS 分隔符设置为换行.
    IFS=$'\n'
    echo "File:${line}"
    for value in $line
    do 
        # 以空格为分隔符
        IFS=$' '
        # 成绩小于60 输出到 fail.txt
        if [ $value -lt 60 ]
        then
            IFS=$'\n'
            echo "File:$line"
            echo $line >> fail.txt
            # 只要读到小于60的跳出当前循环
            continue
            # 字符串会跳过if语句
        fi
    done
done