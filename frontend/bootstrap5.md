# Bootstrap5

## container

container 、row、col

基本布局

```html
<div class="container">
  <div class="row">
    <div class="col">123</div>
    <div class="col">456</div>
    <div class="col">789</div>
  </div>
</div>
```

内嵌布局

```html
<div class="container-fluid">
  <h2>Nested Columns</h2>
  <p>Add columns inside other columns:</p>
</div>

<div class="container-fluid">
  <div class="row">
    <div class="col-8 bg-warning">
      .col-8
      <div class="row">
        <div class="col-6 bg-light">.col-6</div>
        <div class="col-6 bg-secondary">.col-6</div>
      </div>
    </div>
    <div class="col-4 bg-success">.col-4</div>
  </div>
</div>
```
