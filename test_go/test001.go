/*
package main

import (
        "fmt"
        "math"
)

// 定义接口
type Shape interface {
        Area() float64
        Perimeter() float64
}

// 定义一个结构体
type Circle struct {
        Radius float64
}

// Circle 实现 Shape 接口
func (c Circle) Area() float64 {
        return math.Pi * c.Radius * c.Radius
}

func (c Circle) Perimeter() float64 {
        return 2 * math.Pi * c.Radius
}

func main() {
        c := Circle{Radius: 5}
        var s Shape = c // 接口变量可以存储实现了接口的类型
        fmt.Println("Area:", s.Area())
        fmt.Println("Perimeter:", s.Perimeter())
}
*/

/*
package main

import "fmt"

func printValue(val interface{}) {
        fmt.Printf("Value: %v, Type: %T\n", val, val)
}

func main() {
        printValue(42)         // int
        printValue("hello")    // string
        printValue(3.14)       // float64
        printValue([]int{1, 2}) // slice
}
*/

/*
package main

import "fmt"

type Reader interface {
        Read() string
}

type Writer interface {
        Write(data string)
}

type ReadWriter interface {
        Reader
        Writer
}

type File struct{}

func (f File) Read() string {
        return "Reading data"
}

func (f File) Write(data string) {
        fmt.Println("Writing data:", data)
}

func main() {
        var rw ReadWriter = File{}
        fmt.Println(rw.Read())
        rw.Write("Hello, Go!")
}
*/

package main

import (
    "fmt"
)

type Phone interface {
    call()
}

type NokiaPhone struct {
}

func (nokiaPhone NokiaPhone) call() {
    fmt.Println("I am Nokia, I can call you!")
}

type IPhone struct {
}

func (iPhone IPhone) call() {
    fmt.Println("I am iPhone, I can call you!")
}

func main() {
    var phone Phone

    phone = new(NokiaPhone)
    phone.call()

    phone = new(IPhone)
    phone.call()

}