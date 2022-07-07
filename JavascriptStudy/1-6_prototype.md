# 드러나는 비밀, 프로토타입
```js
function Food(name){
    this.name = name;
    this.smell = function(){
        console.log(this.name + "냄새가 난다.");
    }
}
var myFood = new Food("로제 파스타");
var myFood2 = new Food("청란젓");

console.log(myFood.smell === myFood2.smell);    //false
```
- myFood.smell 메소드와 myFood2.smell 메소드는 서로 다른 참조를 한다.
  - 객체를 생성할 때마다 별개의 함수가 계속 만들어진 것!
  - 좀 더 효율적인 방법?

```js
function smell(){
    console.log(this.name + "냄새가 난다");
}
function Food(name){
    this.name = name;
    this.smell = smell;
}
var myFood = new Food("로제 파스타");
var myFood2 = new Food("청란젓");
myFood.smell();
myFood2.smell();
console.log(myFood.smell === myFood2.smell);    //true
```
- 이제 두 객체의 메소드는 같은 함수를 참조한다.
- myFood.constructor === Food       // true
  - Food를 만들 때 name, smell만 만들었는데 constructor 프로퍼티는 왜 들어가있는건가?
- 자바스크립트에서는 생성자의 prototype 프로퍼티를 통해 타입의 특징을 정의한다.
  - constructor 메소드는 Object 타입의 프로퍼티이며 prototype에 의해 정의되었다.
    - Object.prototype.constructor
- 모든 인스턴스는 내부에 [[Prototype]] 프로퍼티를 가지며, 이를 통해 생성자의 prototype 프로퍼티를 추적한다.

```js
Food.prototype.smell = function(){
    console.log(this.name + "냄새가 난다");
}
function Food(name){
    this.name = name;
}
var myFood = new Food("로제 파스타");
var myFood2 = new Food("청란젓");
myFood.smell();
myFood2.smell();
console.log(myFood.smell === myFood2.smell);    //true
```
- 인스턴스에서 생성자의 [[Prototype]]을 타고 올라가며 프로퍼티를 탐색하는 현상을 프로토타입 체인이라고 한다.

## 정리
- 자바스크립트는 생성자의 prototype 프로퍼티를 통해 타입의 특징을 정의한다.
- 모든 인스턴스는 내부에 [[Prototype]] 프로퍼티를 가지며 이를 통해 생성자의 prototype 프로퍼티를 추적한다.
- 인스턴스에서 생성자의 [[Prototype]]을 타고 올라가며 프로퍼티를 탐색하는 현상을 프로토타입 체인 이라고 한다.