# 객체 공장장, 생성자
- 생성자란 앞에 new 연산자가 붙은 함수를 의미하며 인스턴스를 만들 수 있다.
  - 예를 들어 new Object(), new Array()는 자바스크립트의 내부적으로 존재하는 내장 생성자이다.
```js
var myArray = new Array(1, 2, 3);
console.log(myArray);   //[1, 2, 3]
```
- 사용자가 직접 새로운 타입을 만들수도 있다.
```js
function MyOwn(){}  
//   <생성자 함수>
var myObj = new MyOwn();
//<인스턴스>     <생성자>
```
- 생성자와 인스턴스의 관계는 instanceof와 constructor 메소드를 통해 확인할 수 있다.
```js
function MyOwn(){

}
var myObj = new MyOwn();

console.log(myObj instanceof MyOwn);        // true
console.log(myObj.constructor === MyOwn);   // true
```

- 생성자는 왜 만드나요?
  - 생성자의 중요한 기능은 바로 동일한 프로퍼티와 메소드를 가진 객체를 쉽게 대량생산 하는데 있다.
```js
function Food(taste){
    console.log(this.constructor);

    this.taste = taste;
    this.smell = function(){
        console.log(this.taste + "냄새가 난다.");
    }
}
myFood1 = new Food("특재 파스타");  //this -> 인스턴스 가리킴
myFood1.smell();    //"특재 파스타냄새가 난다."

myFood2 = new Food("해물 파스타");
myFood2.smell();    //"해물 파스타냄새가 난다."

myFood3 = Food("특재 파스타");  //this -> Window 전역객체 가리킴

```
- 생성자의 new 연산자는 매우 중요하다!
  - new 연산자가 붙으면 함수의 this는 인스턴스를 참조하게 되며, new 연산자가 자동으로 인스턴스를 반환하기 때문에 함수 안에 return 연산자도 필요 없어지게 된다.

- 만약 생성자 함수에 new 연산자가 없다면
  - 생성자 함수는 단순히 평범한 함수일 뿐이며, this는 전역객체를 가리키게 된다.


## 정리
- 생성자란 앞에 new 키워드가 붙은 함수를 의미한다.
- 생성자의 중요 기능은 동일한 프로퍼티와 메소드를 가진 객체를 쉽게 대량생산하는데 있다.
- 생성자 함수의 new 연산자는 인스턴스를 참조한다.

