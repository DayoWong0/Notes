# Vue

## chapter3 component

### Excise 1

参考

- （练习源码）[Learning-Vuejs-2/chapter3/vue-shopping-list-simple-components at master · PacktPublishing/Learning-Vuejs-2](https://github.com/PacktPublishing/Learning-Vuejs-2/tree/master/chapter3/vue-shopping-list-simple-components)
- （练习答案）[Learning-Vuejs-2/Appendix/chapter3/vue-shopping-list-simple-components at master · PacktPublishing/Learning-Vuejs-2](https://github.com/PacktPublishing/Learning-Vuejs-2/tree/master/Appendix/chapter3/vue-shopping-list-simple-components)

- https://cn.vuejs.org/v2/api/#vm-emit

  配合额外的参数使用 `$emit`

`$emit`，子组件向父组件发送数据。

答案解析：

- Attach the addItem method to add-item-component in which we will emit an event and pass this component's newItem property to it. 

  ```html
        <add-item-component
          v-on:add="addItem"
          :items="items"
        ></add-item-component>
  ```

  

- Modify/simplify the addItem method of the parent component. It should now just receive a text and add it to its items property. 

  ```js
  new Vue({
    el: '#app',
    data: data,
    methods: {
      addItem: function (text) {
        this.items.push({
          text: text,
          checked: false
        })
      }
    }
  })
  ```

  

- Attach the v-on modifier with the name of the event to the component's invocation inside the main markup that will call the addItem method each time the event is emitted. 

  子组件中方法，v-on 绑定在第一条

  ```javascript
    methods: {
      addItem: function () {
        var text
  
        text = this.newItem.trim()
        if (text) {
          this.$emit('add', this.newItem)
          this.newItem = ''
        }
      }
    }
  ```

网页中点击 `Add`，调用子组件的 `addItem`方法，此方法内部用 `this.$emit('add', this.newItem);`，传递 `newItem`数据给父组件，由于

`v-on:add="addItem",在父组件中绑定了，则调用父组件里的 `addItem`方法，父组件的 `addItem`方法接受到一个数据，再push 到数组上。

### SingleFileComponent

#### Style And scoped

css 标签加上 `scoped` 属性，只有 component 中的对应属性会生效，不加的话，整个页面的相应属性都会生效。类似于全局变量和局部变量的区别，`scoped`就是局部变量标识符。

```css
<style scoped>
	h1{
        color: red;
	}
</style
```

### Summary

In this chapter, you learned about Vue components and how to use them. You saw how to 

create and register them using a classic approach (application that uses HTML, CSS, and 

JavaScript) and you also saw how easy it is to create and manipulate them using a single-file 

components approach. Things to retain: 

- While variables are created using CamelCased format, in order to be able to use 

  components inside templates, you must apply the corresponding kebab-cased format, for 

  example, MyBeautifulComponent -> my-beautiful-component 

- Attributes data and el inside the component must be functions and not objects: {data: 

  function () {}} 

- If you want the style of the component not to leak to the global scope, add a scoped 

  attribute to it: `<style scoped></style>`

## Chapter 4. Reactivity – Binding Data to Your Application

Summing it up, in this chapter, we are going to: 

- Revisit the data binding syntax 

- Apply data binding in our applications 

- Iterate over the array of elements and render each element using the same template with 

  different data 

- Revisit and apply the shorthands of data and events binding in our applications

### **Using expressions and filters** 

#### expressions 

`{{}}` 这里面可以用 JavaScript 表达式

```javascript
<template>
  <div>
    <h3>{{ title }}</h3>
    <p>
      {{ Math.pow(5, 2) }}
    </p>
  </div>
</template>
```

#### filters

Filters are just functions. They are created by 

us and applied by using the pipe symbol: |. If you create a filter that makes letters uppercase 

and call it uppercase, in order to apply it, just use it after the pipe symbol inside the mustache 

interpolation: 

`<h3> {{ title | lowercase }} </h3> `

You can chain as many filters as you want, for example, if you have filter A, B, C, you can do 

something like {{ key | A | B | C }}. Filters are created using Vue.filter syntax. Let's 

create our lowercase filter: 

//main.js 

Vue.filter('lowercase', (key) => { 

return key.toLowerCase() 

})



##### 定义：

```javascript
//main.js 
Vue.filter('leftpad', (value) => {
  if (value >= 10) {
    return value
  }
  return '0' + value
})
```

##### 使用

```javascript
<template>
  <div class="well">
    <div class="pomodoro-timer">
      <span>{{ min | leftpad }}:{{ sec | leftpad }}</span>
    </div>
  </div>
</template>
```

### Two-way binding using the v-model directive

Just remember, this directive can only be used with the following elements: 

- `<input> `

- `<select> `

- `<textarea>`

#### Two-way binding between components

two-way binding between components cannot be 

easily achieved using the v-model directive. 

Due to architectural reasons, Vue just prevents 

children from easily changing the parents' scope. 

That's why we used the events system

### Binding attributes using the v-bind directive

- v-bind:src="src" 

- v-bind:class="className" 

Any expression can be written inside the "". The data properties can be used as well

### **Conditional rendering using v-if and v-show directives** 

The v-if directive allows to conditionally render the whole element, which might also be a 

component element depending on some condition. The condition can be any expression and it 

can use the data properties as well. 

- difference

  - v-show 

    v-show attribute will always 

    render the element, just applying display:none CSS property when the result of the condition is false.

    when the condition is not 

    fulfilled, the element is rendered as well with the `display:none` CSS property.

  - v-if

    条件不满足，元素不渲染

    When the condition is not met, the element is not rendered

- How do you decide which one is better to use?

  - use v-show with frequently changing properties

  - v-if if the condition will not change too much during runtime

### **Array iteration using the v-for directive**

### **Event listeners using the v-on directive**

`v-on:click="myMethod" `

```javascript
<script> 
    export default { 
	  methods: { 
          myMethod () { 
              //do something nice 
          } 
      	} 
	   } 
 </script>
```

All the data and props attributes are accessible inside the methods using the this keyword. 



#### change  title method

Let's do the same for title changing. The only difference is that the adding items, we used a 

custom add event and here we will use the native input event. 

### Shorthands

- v-bind:items="items" 

  :items="items" 

- v-bind:class=' $index === 0 ? "active" : ""' 

  :class=' $index===0 ? "active" : ""' 

- v-on:keyup.enter="addItem" 

  @keyup.enter="addItem"

## **Chapter 5. Vuex – Managing State in Your** Application 

Summing it up, in this chapter, we are going to: 

- Understand the difference between local and global application states 

- Understand what Vuex is and how it works 

- Learn how to use data from the global store 

- Learn about store getters, mutations, and actions 

- Install and use the Vuex store in the shopping list and Pomodoro applications

The Vuex store is designed in such a way that it is not possible to change its state 

from any component.

### **How does the store work and what is so special** **about it?** 

The Vuex store contains essentially two things: **state** and **mutations**. State is an object that 

represents the initial state of the application data. Mutations is also an object containing action 

functions that affect the state. Vuex store is just a plain JavaScript file that exports these two 

objects and tells Vue to use Vuex (Vue.use(Vuex)). Then it can be imported into any other 

component. If you import it in the main App.vue file and register the store on the Vue 

application initialization, it is passed to the whole children chain and can be accessed through 

the this.$store variable. 

### Store state and getters

## Chapter 6. Plugins – Building Your House with Your Own Bricks

## Chapter 7. Testing – Time to Test What We Have Done So Far!

- Talk about the importance of unit and end-to-end tests 
- Implement unit tests for the Pomodoro and shopping list applications 
- Learn how to mock server responses in unit tests 
- Implement end-to-end tests for both applications using Nightwatch

### Unit tests for Vue application

1. Import a component. 
2. Instantiate it by passing it to the Vue function. 
3. Mount it.