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

```html
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
> 设置元素定位要先设置 `position` 属性，否则不会生效。之后再使用 `top`、`bottom`、`left`、`right` 进行定位，
>
> 一般只选择 2 个进行定位，意思是 距离 top/bottom/left/right 有多少距离

#### position: static;

> HTML elements are positioned static by default.
>
> Static positioned elements are not affected by the top, bottom, left, and right properties.
>
> An element with `position: static;` is not positioned in any special way; it is always positioned according to the normal flow of the page
>
> 所有元素默认排列方式 像 `block` `inline` 

#### position: relative;

> An element with `position: relative;` is positioned relative to its normal position.
>
> Setting the top, right, bottom, and left properties of a relatively-positioned element will cause it to be adjusted away from its normal position. Other content will not be adjusted to fit into any gap left by the element.
>
> relative 相对定位，是相对正常位置来说的，这点容易忘记。

#### position: fixed;

> An element with `position: fixed;` is positioned relative to the viewport, which means it always stays in the same place even if the page is scrolled. The top, right, bottom, and left properties are used to position the element.
>
> A fixed element does not leave a gap in the page where it would normally have been located.
>
> Notice the fixed element in the lower-right corner of the page.
>
> fixed 是固定的，（相对于浏览器页面来定位的？），top，right，bottom，left 属性给它定位

#### position: absolute;

> An element with `position: absolute;` is positioned relative to the nearest positioned ancestor (instead of positioned relative to the viewport, like fixed).
>
> However; if an absolute positioned element has no positioned ancestors, it uses the document body, and moves along with page scrolling.
>
> **Note:** A "positioned" element is one whose position is anything except `static`.
>
> - absolute 绝对定位，相对于最近的有定位属性的祖先元素进行定位，static 除外（static 为每个元素默认的属性，这个需要排除）
>
> - 若祖先元素都没有定位属性，会相对于 `document body` 定位。
>
>   假设有一需要定位的元素，有时会特意在它祖先元素上手动加上 `position`属性，但只设置这一个属性，不加 top、bottom 等属性，方便它定位。

#### position: sticky;

> An element with `position: sticky;` is positioned based on the user's scroll position.
>
> A sticky element toggles between `relative` and `fixed`, depending on the scroll position. It is positioned relative until a given offset position is met in the viewport - then it "sticks" in place (like position:fixed).
>
> sticky 属性叫附着属性？基于页面滚动的位置来说的，在 `relative` 和 `fixed` 之间切换。

>**Note:** Internet Explorer does not support sticky positioning. Safari requires a -webkit- prefix (see example below). You must also specify at least one of `top`, `right`, `bottom` or `left` for sticky positioning to work.
>
>- ie 不支持这个属性，Safari 要用 `-webkit-sticky`
>- 至少指定一个属性，当此元素离 top/right... 多远时，转为 fixed。

页面内嵌广告经常使用这种，当你下滑的时候给你看广告。

#### Overlapping Elements

> When elements are positioned, they can overlap other elements.
>
> The `z-index` property specifies the stack order of an element (which element should be placed in front of, or behind, the others).
>
> An element can have a positive or negative stack order
>
> `z-index` 多个元素重合，谁显示到外面，是数字，可正可负，数字大的优先展示。（默认的 `z-index`为 0 ？）

> An element with greater stack order is always in front of an element with a lower stack order.
>
> **Note:** If two positioned elements overlap without a `z-index` specified, the element positioned last in the HTML code will be shown on top.
>
> - `z-index` 数字大的优先展示
> - 元素没有设置 `z-index` 时，HTML 代码中靠后的元素先展示（后渲染的优先展示）

#### All CSS Positioning Properties

| Property                                                     | Description                                      |
| :----------------------------------------------------------- | :----------------------------------------------- |
| [bottom](https://www.w3schools.com/cssref/pr_pos_bottom.asp) | Sets the bottom margin edge for a positioned box |
| [clip](https://www.w3schools.com/cssref/pr_pos_clip.asp)     | Clips an absolutely positioned element           |
| [left](https://www.w3schools.com/cssref/pr_pos_left.asp)     | Sets the left margin edge for a positioned box   |
| [position](https://www.w3schools.com/cssref/pr_class_position.asp) | Specifies the type of positioning for an element |
| [right](https://www.w3schools.com/cssref/pr_pos_right.asp)   | Sets the right margin edge for a positioned box  |
| [top](https://www.w3schools.com/cssref/pr_pos_top.asp)       | Sets the top margin edge for a positioned box    |
| [z-index](https://www.w3schools.com/cssref/pr_pos_z-index.asp) | Sets the stack order of an element               |

### CSS Layout - Overflow

> The CSS `overflow` property controls what happens to content that is too big to fit into an area.
>
> Overflow：溢出。容器包不住内容时的处理

#### CSS Overflow

> The `overflow` property specifies whether to clip the content or to add scrollbars when the content of an element is too big to fit in the specified area.
>
> The `overflow` property has the following values:
>
> - `visible` - Default. The overflow is not clipped. The content renders outside the element's box
> - `hidden` - The overflow is clipped, and the rest of the content will be invisible
> - `scroll` - The overflow is clipped, and a scrollbar is added to see the rest of the content

> **Note:** The `overflow` property only works for `block elements` with a `specified height`.
>
> **Note:** In OS X Lion (on Mac), scrollbars are hidden by default and only shown when being used (even though "overflow:scroll" is set).
>
> - `overflow` 属性 对 block 元素且有固定高度的有效
> - Mac OS X的 `scroll` 属性不支持

##### overflow: visible

默认属性，超出部分直接溢出显示，相当于不做任何处理。

##### overflow-x and overflow-y

> The `overflow-x` and `overflow-y` properties specifies whether to change the overflow of content just horizontally or vertically (or both):
>
> `overflow-x` specifies what to do with the left/right edges of the content.
> `overflow-y` specifies what to do with the top/bottom edges of the content.
>
> x 或 y 方向溢出处理

### CSS Layout - float and clear

[经验分享：CSS浮动(float,clear)通俗讲解 - 杨元 - 博客园](https://www.cnblogs.com/iyangyuan/archive/2013/03/27/2983813.html)

> The CSS `float` property specifies how an element should float.
>
> The CSS `clear` property specifies what elements can float beside the cleared element and on which side.

#### The float Property

> The `float` property is used for positioning and formatting content e.g. let an image float left to the text in a container.
>
> The `float` property can have one of the following values:
>
> - left - The element floats to the left of its container
> - right - The element floats to the right of its container
> - none - The element does not float (will be displayed just where it occurs in the text). This is default
> - inherit - The element inherits the float value of its parent
>
> In its simplest use, the `float` property can be used to wrap text around images.
>
> `float` 用于定位和排版，例如让图片显示在文字左边。

#### The clear Property

>
>
>The `clear` property specifies what elements can float beside the cleared element and on which side.
>
>The `clear` property can have one of the following values:
>
>- none - Allows floating elements on both sides. This is default
>- left - No floating elements allowed on the left side
>- right- No floating elements allowed on the right side
>- both - No floating elements allowed on either the left or the right side
>- inherit - The element inherits the clear value of its parent
>
>指明元素的左边和右边是否允许其他`float`元素 

> The most common way to use the `clear` property is after you have used a `float` property on an element.
>
> When clearing floats, you should match the clear to the float: If an element is floated to the left, then you should clear to the left. Your floated element will continue to float, but the cleared element will appear below it on the web page.
>
> The following example clears the float to the left. Means that no floating elements are allowed on the left side (of the div)
>
> https://www.w3schools.com/css/tryit.asp?filename=trycss_layout_clear
>
> clear 一般和 float 同时使用，某个元素使用了 float，但是另一个元素不能和 float 元素出现在它的某一边，那么它会出现在下一行。

#### The clearfix（清除浮动） Hack

> If an element is taller than the element containing it, and it is floated, it will "overflow" outside of its container
>
> Then we can add `overflow: auto;` to the containing element to fix this problem
>
> https://www.w3schools.com/css/tryit.asp?filename=trycss_layout_clearfix
>
> 容器用了 `overflow: auto` 可以在固定容器的 width 或 height 小了的时候可以自动增大包含它里面的内容，但是如果 margin 和 padding 没控制好，会出现 scrollbar，用户体验不好。用下面的方法更好

```css
.clearfix::after {
  content: "";
  clear: both;
  display: table;
}
```

https://www.w3schools.com/css/tryit.asp?filename=trycss_layout_clearfix2

相当于在 `clearfix`类里加了一个空白的元素（加的这个元素是 `.clearfix` 的子元素），设置它两边都不允许有 float 元素，所以这 clearfix 元素下的子类都浮动到下一行去了（仍然在 `clearfix` 里）

~~这个例子没看懂~~

简单来说就是：用了上面的代码的 `clearfix`类，设置它里面的元素 float 属性，它的子元素会到下一行

### CSS Layout - Float Examples

[CSS Layout - Float Examples](https://www.w3schools.com/css/css_float_examples.asp)

这一节的例子比较重要

[Tryit Editor v3.6](https://www.w3schools.com/css/tryit.asp?filename=trycss_float5)