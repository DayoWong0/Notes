init
```shell
npm install
```

run
```shell
docsify serve ./
```

git-commit-push-mac
```shell
git add . && git commit -m `date +%Y/%m/%d-%H:%M:%S` && git push
```

push-win-powershell
```shell
git add . ; $date1 = date; git commit -m $date1; git push
```

push-win-cmd
```shell
git add . ; git commit -m %date% ; git push
```



```shell
{
  "scripts": {
    "init": "npm install",
    "run": "docsify serve ./",
    "git-commit-push-mac": "git add . && git commit -m `date +%Y/%m/%d-%H:%M:%S` && git push",
    "git-commit-push-win": "git add . ; git commit -m %date% ; git push",
    "git-push": "git push"
  },
  "dependencies": {
    "docsify-cli": "^4.4.2"
  }
}
```