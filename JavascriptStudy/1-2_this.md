# 좀 더 this 하기 <call, apply, bind>
## this
- this: 함수를 호출하는 객체
- this가 존재하는 이유?
  - this를 이용하면 함수를 다른 객체에서도 재사용 할 수 있다.
```js
var myDinner = {
    name: "김치찌개",
    menu: function(){
        console.log("오늘 저녁은 " + myDinner.name);
    }
}
myDinner.menu();
/*
위와 같은 객체가 있을 때
menu 함수는 myDinner 변수 이름이 수정될 경우나, menu 함수 자체를 다른 객체에서 사용하고 싶을 경우 사용이 불편하다. => 함수 재사용이 불편함
ex1) 변수 myDinner의 이름이 yourDinner로 바꾸면 console.log 안의 myDinner도 이름을 변경해야 함.
ex2) menu 함수만 사용하고 싶을 때, myDinner객체에 name이라는 변수가 있을지 모름.
*/
```
```js
function menuGlobal(){
    console.log("오늘 저녁은 " + this.name);
}
var myDinner = {
    name : "김치찌개",
    menu : menuGlobal
}
myDinner.menu();       // 오늘 저녁은 김치찌개

var yourDinner = {
    name : "된장찌개",
    menu : menuGlobal
}
yourDinner.menu();      // 오늘 저녁은 된장찌개
```

## this 제어하기
- 일반적으로 this의 값은 자동으로 할당되지만, 상황에 따라 제어할 수 있어야 한다.
### call()
  - call 메서드는 this의 값을 바꿀 수도 있고, 함수를 실행할 때 사용할 인수도 전달할 수 있다.
```js
function menuGlobal(item){
    console.log("오늘 저녁은 " + item + this.name);
}
var myDinner = {
    name : "김치찌개"
}
var yourDinner = {
    name : "된장찌개"
}

// call은 menuGlobal이 어떤 객체를 바라볼지 정해줌.
// -> this는 myDinner를 가리킴
menuGlobal.call(myDinner, "묵은지")
// "오늘 저녁은 묵은지김치찌개"

menuGlobal.call(yourDinner, "삼겹살")
// "오늘 저녁은 삼겹살된장찌개"
```
  
### apply()
- apply 메서드는 함수를 실행할 때 인수를 배열로 묶어 한번에 전달한다.
```js
function menuGlobal(item1, item2){
    [item1, item2].forEach(function(el){
        console.log("오늘 저녁은 " + el + this.name);
    }, this);
    // forEach 함수에서 this를 전달받으려면 인자로 this를 선언해야 상위 스코프의 this를 바라보게 함
    // forEach 변수로 this를 써주지 않으면 this.name은 해당 함수를 호출하는 window 객체 (전역객체)를 바라봄 
}
var myDinner = {
    name : "김치찌개"
}
var yourDinner = {
    name : "된장찌개"
}
menuGlobal.apply(myDinner, ["묵은지", "삼겹살"]);
/*
"오늘 저녁은 묵은지김치찌개"
"오늘 저녁은 삼겹살김치찌개"
*/
menuGlobal.apply(yourDinner, ["두부", "애호박"]);
/*
"오늘 저녁은 두부된장찌개"
"오늘 저녁은 애호박된장찌개"
*/
menuGlobal.call(myDinner, ["묵은지", "삼겹살"]);
/*
오늘 저녁은 묵은지,삼겹살김치찌개
오늘 저녁은 undefined김치찌개
*/
```
- call()과 apply()의 차이
  - call은 함수를 실행할 때 전달할 인수를 하나 하나 전달한다.
  - apply는 전달할 인수를 배열로 묶어 한번에 전달한다. 그래서 인수를 두개만 사용한다. (this를 지정할 객체, 전달할 인수)
  - 인수를 배열로 보낸다는 점 빼고는 call과 apply는 동일한 기능을 수행한다.
  
### bind()
- bind 메서드는 ES5에서 추가됨
- this 값을 어디서 사용하든 호출 객체가 바뀌지 않게 고정시켜버린다.
```js
function menuGlobal(item){
    console.log("오늘 저녁은 " + item + this.name)
}
var myDinner = {
    name : "김치찌개"
}
var yourDinner = {
    name : "된장찌개"
}
var menuGlobalForMe = menuGlobal.bind(myDinner);
console.log(menuGlobalForMe("묵은지"));
/*
"오늘 저녁은 묵은지김치찌개"
undefined (menuGlobal 함수의 return이 없어서 undefined가 찍힘)
*/

var menuGlobalForYou = menuGlobal.bind(yourDinner);
console.log(menuGlobalForYou("삼겹살"));
/*
"오늘 저녁은 삼겹살된장찌개"
undefined
*/

myDinner.menuMine = menuGlobalForYou;
myDinner.menuMine("묵은지");
/*
"오늘 저녁은 묵은지된장찌개"
undefined
*/
```

### 화살표 함수와 this
- 화살표 함수의 this는 일반적인 this처럼 함수를 호출한 객체를 할당하지 않고, 바로 상위 스코프의 this를 할당한다.
```js
function menuGlobal(item1, item2){
    console.log(this);
    [item1, item2].forEach((el) => {
        console.log("오늘 저녁은 " + el + this.name);
    });
}
var myDinner = {
    name : "김치찌개"
}
var yourDinner = {
    name : "된장찌개"
}
menuGlobal.apply(myDinner, ["묵은지", "삼겹살"]);
/*
{name : "김치찌개"}
"오늘 저녁은 묵은지김치찌개"
"오늘 저녁은 삼겹살김치찌개"
*/
```

## 정리
- this는 함수를 호출하는 객체를 의미한다.
- call과 apply는 this에 할당되는 객체를 지정할 수 있다.
- bind는 this에 할당되는 객체가 고정된 새로운 함수를 생성한다.
- 화살표 함수에서 this는 상위 스코프의 객체를 할당받는다.