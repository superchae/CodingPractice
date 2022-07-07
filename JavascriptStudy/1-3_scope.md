# 저격수의 소양, Scope
## 유효범위(scope)
- 변수의 접근성과 생존 기간을 제어한다.
- 이름이 충돌하는 문제를 덜어주고, 자동으로 메모리를 관리한다.
```js
var func1 = function(){
    var a = 1;
    var b = 2;
    console.log(a + b);
    return a + b;
};

var a = 20;
func1();    // 3
console.log(b);     // error: b is not defined
```

## 자바스크립트의 유효범위
1. 전역 스코프
   - 스크립트의 어디서든 접근이 가능하기 때문에 사용이 쉽다.
   - 타인과의 협업, 라이브러리 사용시 충돌의 가능성이 있다.
2. 함수 스코프
   - 함수 내부에서 정의된 변수와 매개변수는 함수 외부에서 접근할 수 없다.
   - 함수 내부에서 정의된 변수라면 함수의 어느 부분에서도 접근 가능하다.
    ```js
    var func = function(){
        var a = 1;
        var b = 2;
        var func2 = function(){
            var b = 5;
            var c = 6;
            a = a + b + c;      //a는 부모에 있어서 접근 가능
            console.log(a); 
        };
        func2();    // 12
    };
    func();
    ```
    ```js
    function test(){
        val = "hello";  // 선언된 변수가 아님 -> 전역변수로 인식
        var val2 = "world";
    }
    test();
    console.log(val);   // "hello"
    console.log(val2);  // error: val2 is not defined
    ```
3. 블록 스코프 (es6)
    - 중괄호 안에서만 접근 가능하다.
    - 블록 내부에 정의된 변수는 볼록의 실행이 끝나면 해제된다.
    ```js
    if(true){
        var value = "hello";
    }
    console.log(value);     // hello

    if(true){
        let value = "world";
    }
    console.log(value);     // hello
    // let은 블록스코프 내에서만 존재 -> 전역에 선언한 value값을 가져옴
    ```

## 정리
- 스코프는 변수의 접근성과 생존 기간을 제어한다.
- 스코프는 이름이 충돌하는 문제를 덜어주고, 자동으로 메모리를 관리한다.
- 자바스크립트에는 전역 스코프, 함수 스코프, 블록 스코프가 존재한다.