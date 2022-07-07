# JS 고유의 개념, 타입 <원시 타입, 참조 타입, 원시 래퍼 타입>

## 원시 타입
- 있는 그대로 저장되는 데이터를 표현한다.
```js
var value = "7";
console.log(value);     // 7
```
- 원시 타입의 종류
  - 불리언: true, false
  - 숫자: 1, 2, 3, ...
  - 문자열: "Hello World"
  - null
  - undefiend
- 원시 타입의 특징
  - 원시값을 변수에 할당하면 값이 복사되어 들어간다.
  - 즉, 원시값이 할당된 변수들은 모두 자기 자신만의 고유한 값을 가지게 된다.
```js
var one = 1;
var two = 2;
one = two;
one = 3;
console.log(two);   // 2
```
- typeof
  - 원시값의 종류를 알 수 있게 해주는 메서드
  - null 타입에 주의
```js
console.log(typeof 1);          //number
console.log(typeof "hi");       //string
console.log(typeof true);       //boolean
console.log(typeof null);       //object(객체, 참조타입) -> js 재단의 실수..
console.log(typeof undefined);  //undefined

//null인지 확인하기 위해서는 이 방법을 사용하는 것이 확실함
if(value === null){} 
```

## 참조 타입
- 자바스크립트 객체
- 참조 타입의 종류
  - 객체: {}
  - 배열: []
  - 함수: function
  - Date
  - 정규표현식: RegExp
  - * 원시 타입 빼고 전부 참조 타입으로 봐도 좋다.*
- 참조 타입의 특징
  - 참조 타입은 변수에 값을 직접 저장하지 않는다.
  - 변수에 저장되는 것은 메모리 안에서 객체의 위치를 가리키는 "포인터"다.
  - 무엇이 저장되느냐, 이것이 원시 타입과 참조 타입의 가장 큰 차이다.
```js
var objOne = {one : 1};
var objTwo = {two : 2};
objTwo = objOne;
console.log(objTwo);    // {one : 1}
objTwo.one = 3;
console.log(objOne);    // {one : 3}
console.log(objTwo);    // {one : 3}
```

## 원시 래퍼 타입
- 하지만 신기하게도 원시타입도 마치 참조타입처럼 (객체처럼) 사용할 수 있다.
```js
var str = "hello world";
console.log(str.length);    // 11
// str은 원시타입이지만 객체처럼 메소드를 사용할 수 있다.
```
- 원시 래퍼 타입
  - 원시 타입을 객체처럼 편리하게 사용하도록 도와준다.
- 원시 래퍼 타입의 종류
  - String
  - Number
  - Boolean
- 원시 래퍼 타입의 특징
  - 원시 타입을 객체처럼 사용하는 순간, 자바스크립트 내부에서 사용하는 데이터의 인스턴스를 만들게 된다. 이렇게 만들어진 객체는 코드를 실행 후 바로 다음 줄에서 파괴된다.
  - 이러한 과정을 오토박싱(autoboxing)이라고 한다.
- 원시래퍼타입 ex.1
```js
var name = "bit";
console.log(name.concat("coin"));   // "bitcoin"

// JS 내부에서 원시래퍼타입으로 동작하는 과정 
var name = "bit";
var temp = new String(name);
console.log(temp.concat("coin"));
temp = null;
```

- 원시래퍼타입 ex.2 
```js
var name = "bit";
name.coin = "coin";
console.log(name.coin);     // undefined (값이 할당되지 않음)

// JS 내부 동작
var name = "bit";
var temp = new String(name);
temp.coin = "coin";
temp = null;

var temp = new String(name);
console.log(temp.coin);     // undefined
```