# CSS-W3CSchool

## reference

- [CSS Tutorial](https://www.w3schools.com/css/default.asp)

## Problem

- Box Model
  - 理解不到位，需要修改与 `margin` `padding` 时一脸懵逼
  - how to use margin padding
- how does them effect layout
- float clear
  - [CSS Layout - float and clear](#CSS Layout - float and clear)
  - [CSS Layout - Float Examples](#CSS Layout - Float Examples)
  - how to float and clear
  - how does it work `.clearfix`
- box-sizing 属性

- 什么时候需要或者怎么设置 `margin` `padding`，且不会影响与其他元素的对齐
- 

## 易错章节

- [CSS - The :first-child Pseudo-class](#CSS - The :first-child Pseudo-class)

## Trick

- 搭建 HTML 结构之前看下哪些属性会设置相同的，想好`class`

- 写 CSS 顺序，由内到外？

  看 w3cschool 上的例子是这样写的

- 行内元素变为块级元素感觉用 `inline-block` 多些，并且一般都有设置长宽属性或者 `margin` `padding`

  > 行内元素设置 `height` `width` `margin` `padding`等无效，除非转为 `inline-block` 或 `block`

- clearfix

  那个 div 的会合在一起

## Selector

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

[CSS - clearfix清除浮动 - 简书](https://www.jianshu.com/p/9d6a6fc3e398)

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

#### All CSS Float Properties

| Property                                                     | Description                                                  |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [box-sizing](https://www.w3schools.com/cssref/css3_pr_box-sizing.asp) | Defines how the width and height of an element are calculated: should they include padding and borders, or not |
| [clear](https://www.w3schools.com/cssref/pr_class_clear.asp) | Specifies what elements can float beside the cleared element and on which side |
| [float](https://www.w3schools.com/cssref/pr_class_float.asp) | Specifies how an element should float                        |
| [overflow](https://www.w3schools.com/cssref/pr_pos_overflow.asp) | Specifies what happens if content overflows an element's box |
| [overflow-x](https://www.w3schools.com/cssref/css3_pr_overflow-x.asp) | Specifies what to do with the left/right edges of the content if it overflows the element's content area |
| [overflow-y](https://www.w3schools.com/cssref/css3_pr_overflow-y.asp) | Specifies what to do with the top/bottom edges of the content if it overflows the element's content area |

### CSS Layout - display: inline-block

> Compared to `display: inline`, the major difference is that `display: inline-block` allows to set a width and height on the element.
>
> Also, with `display: inline-block`, the top and bottom margins/paddings are respected, but with `display: inline` they are not.
>
> Compared to `display: block`, the major difference is that `display: inline-block` does not add a line-break after the element, so the element can sit next to other elements.
>
> - `display: inline-block` ：是 `display: inline` 和 `display: block` 的部分特征结合
>   - 是行内元素。不会换行(`inline` 的属性)
>   - 可以设置 `width` `height` `margin` `padding` （`block` 的属性）

导航栏经常使用 `ul` `li` `inline-block`

### CSS Layout - Horizontal & Vertical Align

这一节干货很多，用到再来查询。

#### Center Align Elements

> To horizontally center a block element (like <div>), use `margin: auto;`
>
> Setting the width of the element will prevent it from stretching out to the edges of its container.
>
> The element will then take up the specified width, and the remaining space will be split equally between the two margins
>
> - 居中块级元素，用 `margin: auto`,这样适应性好，指定 `width`没有响应式。先分给 `width`长度，剩下的 `margin`平分

> **Note:** Center aligning has no effect if the `width` property is not set (or set to 100%).

#### Center Align Text

> To just center the text inside an element, use `text-align: center;`

#### Center an Image

> To center an image, set left and right margin to `auto` and make it into a `block` element:

#### Left and Right Align - Using position

##### Left and Right Align - Using position

##### Left and Right Align - Using float

#### Center Vertically - Using padding

## CSS Combinators

> A combinator is something that explains the relationship between the selectors

> A CSS selector can contain more than one simple selector. Between the simple selectors, we can include a combinator.
>
> There are four different combinators in CSS:
>
> - descendant selector (space)：后代选择器
> - child selector (>)
> - adjacent sibling selector (+)：临近兄弟选择器
> - general sibling selector (~)
>
> 选择器进阶，这节需要好好学，我写 CSS 写选择器容易出问题

### Descendant Selector

> The descendant selector matches all elements that are descendants of a specified element
>
> ```css
> div p {
>   background-color: yellow;
> }
> ```
>
> 所有的 div 下的 p 标签都被选中, 只要满足 div 下的 p，不管之前还有没有 div。在这一节中作用域最广的选择器

这个标签容易被我滥用

### Child Selector (>)

> The child selector selects all elements that are the children of a specified element.
>
> 一代孩子

### Adjacent Sibling Selector (+)

> The adjacent sibling selector is used to select an element that is directly after another specific element.
>
> Sibling elements must have the same parent element, and "adjacent" means "immediately following".
>
> ```css
> div + p {
>   background-color: yellow;
> }
> ```
>
> - 兄弟选择器
> - div后面（同级）的 第一个 p

### General Sibling Selector (~)

> The general sibling selector selects all elements that are siblings of a specified element.
>
> The following example selects all <p> elements that are siblings of <div> elements
>
> ```css
> div ~ p {
>   background-color: yellow;
> }
> ```
>
> - 普通兄弟选择器
> - div 后面的所有同级 p 标签

### All CSS Combinator Selectors

| Selector                                                     | Example | Example description                                          |
| :----------------------------------------------------------- | :------ | :----------------------------------------------------------- |
| [*element* *element*](https://www.w3schools.com/cssref/sel_element_element.asp) | div p   | Selects all <p> elements inside <div> elements               |
| [*element*>*element*](https://www.w3schools.com/cssref/sel_element_gt.asp) | div > p | Selects all <p> elements where the parent is a <div> element |
| [*element*+*element*](https://www.w3schools.com/cssref/sel_element_pluss.asp) | div + p | Selects the first <p> element that are placed immediately after <div> elements |
| [*element1*~*element2*](https://www.w3schools.com/cssref/sel_gen_sibling.asp) | p ~ ul  | Selects every <ul> element that are preceded by a <p> element |

## CSS Pseudo

### CSS Pseudo-classes

#### What are Pseudo-classes?

> A pseudo-class is used to define a special state of an element.
>
> For example, it can be used to:
>
> - Style an element when a user mouses over it
> - Style visited and unvisited links differently
> - Style an element when it gets focus
>
> 伪类
>
> 类似于
>
> ```css
> /* unvisited link */
> a:link {
>   color: #FF0000;
> }
> 
> /* visited link */
> a:visited {
>   color: #00FF00;
> }
> 
> /* mouse over link */
> a:hover {
>   color: #FF00FF;
> }
> 
> /* selected link */
> a:active {
>   color: #0000FF;
> }
> ```
>
> > **Note:** `a:hover` MUST come after `a:link` and `a:visited` in the CSS definition in order to be effective! `a:active` MUST come after `a:hover` in the CSS definition in order to be effective! Pseudo-class names are not case-sensitive.
> >
> > - `a: hover` 必须定义在 `a: link` 和 `a: visited` 之后，否则不生效。我没注意到这一点

#### Pseudo-classes and CSS Classes

```css
a.highlight:hover {
  color: #ff0000;
}
```

#### Simple Tooltip Hover

> ```css
> p {
>   display: none;
>   background-color: yellow;
>   padding: 20px;
> }
> 
> div:hover p {
>   display: block;
> }
> ```
>
> hover 改变 display 属性

#### CSS - The :first-child Pseudo-class

> The `:first-child` pseudo-class matches a specified element that is the first child of another element.
>
> 容易理解错，下面的是选择第一个 p 标签，而不是选择 p 标签下的第一个子元素(这个方法看下面一节)。
>
> ```html
> <!DOCTYPE html>
> <html>
> <head>
> <style>
> p:first-child {
>   color: blue;
> } 
> </style>
> </head>
> <body>
> 
> <p>This is some text.</p>/* 这个会被选择器选中变成蓝色*/
> <p>This is some text.</p>
> 
> </body>
> </html>
> ```

#### Match the first <i> element in all <p> elements

> In the following example, the selector matches the first <i> element in all <p> elements:

```css
p i:first-child {
  color: blue;
}
```

#### Match all <i> elements in all first child <p> elements

> In the following example, the selector matches all <i> elements in <p> elements that are the first child of another element
>
> ```css
> p:first-child i {
>   color: blue;
> }
> ```
>
> 理解了 [CSS - The :first-child Pseudo-class](#CSS - The :first-child Pseudo-class) 自然就懂了，注意和上面一个的区别

#### CSS - The :lang Pseudo-class

少用

### CSS Pseudo-elements

伪元素

#### What are Pseudo-Elements?

> A CSS pseudo-element is used to style specified parts of an element.
>
> For example, it can be used to:
>
> - Style the first letter, or line, of an element
> - Insert content before, or after, the content of an element

```css
selector::pseudo-element {
  property: value;
}
```

注意是 `::` 双引号

#### The ::first-line Pseudo-element

> The `::first-line` pseudo-element is used to add a special style to the first line of a text.

> **Notice the double colon notation -** `::first-line` versus `:first-line`
>
> The double colon replaced the single-colon notation for pseudo-elements in CSS3. This was an attempt from W3C to distinguish between **pseudo-classes** and **pseudo-elements**.
>
> The single-colon syntax was used for both pseudo-classes and pseudo-elements in CSS2 and CSS1.
>
> For backward compatibility, the single-colon syntax is acceptable for CSS2 and CSS1 pseudo-elements.
>
> - `:` vs `::`
>
>   css3 用 `::` 表示 Pseudo-element，css1 和 css2 用 `:`，便于区分就用 `::`

#### The ::first-letter Pseudo-element

> The `::first-letter` pseudo-element is used to add a special style to the first letter of a text.
>
> 改变第一个单词的样式

#### Pseudo-elements and CSS Classes

```css
p.intro::first-letter {
  color: #ff0000;
  font-size: 200%;
}
```

- 选择到 p 标签 class 为 intro 第一个单词

#### Multiple Pseudo-elements

```css
p::first-letter {
  color: #ff0000;
  font-size: xx-large;
}

p::first-line {
  color: #0000ff;
  font-variant: small-caps;
}
```

搭配使用

#### CSS - The ::before Pseudo-element

这题我会，我用过

> The `::before` pseudo-element can be used to insert some content before the content of an element.
>
> 在某个元素之前(元素内部的前面)插入内容
>
> ```css
> h1::before {
>   content: url(smiley.gif);
> }
> ```
>
> 插入后
>
> ```html
> <h1>::before This is a heading </h1>
> ```
>
> 

#### CSS - The ::after Pseudo-element

> The `::after` pseudo-element can be used to insert some content after the content of an element.
>
> 在某个元素之后(元素内部的后面)插入内容
>
> ```html
> h1::after {
>   content: url(smiley.gif);
> }
> ```
>
> 插入后
>
> ```html
> <h1>This is a heading ::after </h1>
> ```

#### CSS - The ::selection Pseudo-element

> The `::selection` pseudo-element matches the portion of an element that is selected by a user.
>
> 用户双击或者拖动鼠标等选择了的元素，就叫做 `::selection`，根据用户动态选择在改变的

## CSS Opacity / Transparency

透明度

### Transparent Image

> The `opacity` property can take a value from 0.0 - 1.0. The lower value, the more transparent:
>
> - 透明度 0.0 - 1.0，数值越小越透明
> - 默认透明度为 1，即不透明

### Transparent Hover Effect

> The `opacity` property is often used together with the `:hover` selector to change the opacity on mouse-over
>
> 配合 `hover` 选择器改变透明度

### Transparent Box

> When using the `opacity` property to add transparency to the background of an element, all of its child elements inherit the same transparency. This can make the text inside a fully transparent element hard to read
>
> 有继承效果给子元素

### Transparency using RGBA

> If you do not want to apply opacity to child elements, like in our example above, use **RGBA** color values
>
> - 无继承效果给子元素
>
> An RGBA color value is specified with: rgba(red, green, blue, *alpha*). The *alpha* parameter is a number between 0.0 (fully transparent) and 1.0 (fully opaque)
>
> - RGBA 中的 A 是 Alpha，范围也是 0.0- 1.0，1.0 为完全不透明，默认的

### Text in Transparent Box

## CSS Navigation Bar

### Navigation Bar = List of Links

## CSS Attribute Selectors

## CSS [attribute] Selector

```css
a[target] {
  background-color: yellow;
}
```

```html
<a href="http://www.wikipedia.org" target="_top">wikipedia.org</a>
```

### CSS [attribute="value"] Selector

```css
a[target="_blank"] {
  background-color: yellow;
}
```

### CSS [attribute~="value"] Selector

> The `[attribute~="value"]` selector is used to select elements with an attribute value containing a specified word.

### CSS [attribute|="value"] Selector

> The `[attribute|="value"]` selector is used to select elements with the specified attribute starting with the specified value.

### Styling Forms

```css
input[type="text"] {
  width: 150px;
  display: block;
  margin-bottom: 10px;
  background-color: yellow;
}

input[type="button"] {
  width: 120px;
  margin-left: 35px;
  display: block;
}
```

## CSS Forms