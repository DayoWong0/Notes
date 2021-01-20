# CSS-W3CSchool

## reference

- [CSS Tutorial](https://www.w3schools.com/css/default.asp)

## Box Model

### Margin

- [CSS Margin](https://www.w3schools.com/css/css_margin.asp)

#### Margin Auto

margin: auto，水平居中

> **The auto Value**
>
> You can set the margin property to `auto` to horizontally center the element within its container.
>
> The element will then take up the specified width, and the remaining space will be split equally between the left and right margins.

```vue
<template>
  <div class="CSSMargins">
    <h2>Use of margin:auto</h2>
    <p>
      You can set the margin property to auto to horizontally center the element
      within its container. The element will then take up the specified width,
      and the remaining space will be split equally between the left and right
      margins:
    </p>

    <div>
      This div will be horizontally centered because it has margin: auto;
    </div>
  </div>
</template>

<script>
export default {
  name: "CSSMargins",
};
</script>

<style scoped>
div {
  width: 300px;
  margin: auto;
  border: 1px solid red;
}
</style>
```

#### Margin Collapse

> Top and bottom margins of elements are sometimes collapsed into a single margin that is equal to the largest of the two margins.
>
> This does not happen on left and right margins! Only top and bottom margins!
>
> top 和 bottom 两个 margin 有时会结合成一个 margin，共同值为两者最大的。

```html
<!DOCTYPE html>
<html>
  <head>
    <style>
      h1 {
        margin: 0 0 50px 0;
      }

      h2 {
        margin: 20px 0 0 0;
      }
    </style>
  </head>
  <body>
    <p>
      In this example the h1 element has a bottom margin of 50px and the h2
      element has a top margin of 20px. Then, the vertical margin between h1 and
      h2 should have been 70px (50px + 20px). However, due to margin collapse,
      the actual margin ends up being 50px.
    </p>

    <h1>Heading 1</h1>
    <h2>Heading 2</h2>
  </body>
</html>
```

如 h1，h2， 一上一下共两个 block 元素，h1 的 `margin-bottom` 为 50px，h2 的`magin-top` 为 20px，则两个 `margin`的值合并为一个两者中大的一个值 50px，称为 margin 塌陷/合并，

### CSS Padding

#### Padding and Element Width

> The CSS `width` property specifies the width of the element's content area. The content area is the portion inside the padding, border, and margin of an element ([the box model](https://www.w3schools.com/css/css_boxmodel.asp)).
>
> So, if an element has a specified width, the padding added to that element will be added to the total width of the element. This is often an undesirable result.
>
> `width`：规定元素内容长度，如文字部分的 width。padding、border、margin 不包括在 width 之内，见盒子模型，width 为盒子模型 padding 之内的部分

```html
<!DOCTYPE html>
<html>
  <head>
    <style>
      div.ex1 {
        width: 300px;
        background-color: yellow;
      }

      div.ex2 {
        width: 300px;
        padding: 25px;
        background-color: lightblue;
      }
    </style>
  </head>
  <body>
    <h2>Padding and element width</h2>

    <div class="ex1">This div is 300px wide.</div>
    <br />

    <div class="ex2">
      The width of this div is 350px, even though it is defined as 300px in the
      CSS.
    </div>
  </body>
</html>
```

> To keep the width at 300px, no matter the amount of padding, you can use the `box-sizing` property. This causes the element to maintain its width; if you increase the padding, the available content space will decrease.
>
> 用 `box-sizing` 固定此盒子模型 width 为 300 px， padding 增加，content 相应减小，box-sizing 一直为 300 px，不变，盒子大小固定。这里 box-sizing 　属性设置的是　 border-box

### CSS Height and Width

> The `height` and `width` properties are used to set the height and width of an element.
>
> The height and width properties do not include padding, borders, or margins. It sets the height/width of the area inside the padding, border, and margin of the element.
>
> height 和 width 不包含 padding、border、margin

#### Setting max-width

当 width 达到 max-width 后，width 不再增加

```html
<!DOCTYPE html>
<html>
  <head>
    <style>
      div {
        max-width: 500px;
        height: 100px;
        background-color: powderblue;
      }
    </style>
  </head>
  <body>
    <h2>Set the max-width of an element</h2>
    <p>This div element has a height of 100px and a max-width of 500px:</p>

    <div></div>

    <p>Resize the browser window to see the effect.</p>
  </body>
</html>
```

同理有

| [max-height](https://www.w3schools.com/cssref/pr_dim_max-height.asp) | Sets the maximum height of an element |
| -------------------------------------------------------------------- | ------------------------------------- |
| [max-width](https://www.w3schools.com/cssref/pr_dim_max-width.asp)   | Sets the maximum width of an element  |
| [min-height](https://www.w3schools.com/cssref/pr_dim_min-height.asp) | Sets the minimum height of an element |
| [min-width](https://www.w3schools.com/cssref/pr_dim_min-width.asp)   | Sets the minimum width of an element  |

#### Width and Height of an Element

> **Important:** When you set the width and height properties of an element with CSS, you just set the width and height of the **content area**. To calculate the full size of an element, you must also add padding, borders and margins.
>
> 元素大小 = content width/height + paddings + borders + margins

### CSS Outline

> An outline is a line that is drawn around elements, OUTSIDE the borders, to make the element "stand out".
>
> **Note:** Outline differs from [borders](https://www.w3schools.com/css/css_border.asp)! Unlike border, the outline is drawn outside the element's border, and may overlap other content. Also, the outline is NOT a part of the element's dimensions; the element's total width and height is not affected by the width of the outline.
>
> 就是说 outline 是在元素外，在 border 周围，不属于元素内部。

> **Note:** None of the other outline properties (which you will learn more about in the next chapters) will have ANY effect unless the `outline-style` property is set!
>
> `outline-style` 不设置，与它相关的属性都不能生效，所以要用 outline 的属性必须先设置 `outline-style`

## CSS Layout

### CSS Layout - width and max-width

#### Using width, max-width and margin: auto

页面自适应办法

```ht
<!DOCTYPE html>
<html>
<head>
<style>
div.ex1 {
  width: 500px;
  margin: auto;
  border: 3px solid #73AD21;
}

div.ex2 {
  max-width: 500px;
  margin: auto;
  border: 3px solid #73AD21;
}
</style>
</head>
<body>

<h2>CSS Max-width</h2>

<div class="ex1">This div element has width: 500px;</div>
<br>

<div class="ex2">This div element has max-width: 500px;</div>

<p><strong>Tip:</strong> Drag the browser window to smaller than 500px wide, to see the difference between
the two divs!</p>

</body>
</html>

```

为了适应性好，少用 width 多用 max-width？max-width 包含了 width 的功能？

### CSS Layout - The position Property

> There are five different position values:
>
> - `static`
> - `relative`
> - `fixed`
> - `absolute`
> - `sticky`

> Elements are then positioned using the top, bottom, left, and right properties. However, these properties will not work unless the `position` property is set first. They also work differently depending on the position value
>
> 设置元素定位要先设置 `position` 属性，否则不会生效

#### position: static

