# 그것이 알고싶다, <closure>
closure: 중단하다, 폐쇄하다
```js
var outer = function(){
    var a = 1;
    var inner = function(){
        var b = 5;
        var c = 6;
        a = a + b + c;
        console.log(a);
    }
    inner();    // 12
}
```
- 만약 내부 함수가 외부 함수보다 오래 살아있는 경우에, 외부함수에 있던 변수들은 어떻게 되나요?
```js
var outer = function(){
    var a = 1;
    var inner = function(){
        var b = 5;
        var c = 6;
        a = a + b + c;
        console.log(a);
    }
    return inner;   //실행 순서: outer return (outer 함수가 메모리에서 해제됨) -> inner
}
var newInner = outer();
newInner();       // 12
```
  - Inner는 outer가 이미 반환된 후에도 outer의 a에 대한 접근 권한을 가진다.
  - 함수는 자신을 포함하는 함수의 스코프에 접근할 수 있기 때문에


## 클로저
  - 폐쇄된 공간에 대한 접근 권한을 가진 함수 (inner 함수)
  - 이러한 특징을 이용한다면 비공개 데이터를 가진 객체를 만들어 볼 수 있다.
```js
var person = (function(){       //괄호로 감싸서 즉시실행함수
    var age = 15;
    return {                    //객체를 반환하는 함수
        name : "Wade",
        getAge : function(){
            console.log(age);
            return age;
        },
        setAge : function(val){
            age = val;
            console.log(age);
        }
    }   // 즉시실행함수의 return 객체에는 age라는 값이 존재하지 않음
})();
person.getAge();    //15
person.setAge(20);  //20

person.age = 30;
person.getAge();    //20
```

## 정리
- 자바스크립트는 내부 함수에서 자신을 포함하는 외부 함수의 스코프에 접근할 수 있다.
- 내부 함수가 살아있는 상태에서 외부 함수가 파괴되면 외부 함수의 변수들에 대한 접근 권한은 내부 함수만 가지게 된다.
- 폐쇄된 공간에 대한 접근 권한을 가진 함수가 클로저이다.

