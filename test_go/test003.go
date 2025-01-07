/*
package main

import "fmt"

func sum(s []int, c chan int) {
    sum := 0
    for _, v := range s {
        sum += v
    }
    c <- sum // 把 sum 发送到通道 c
}

func main() {
    s := []int{7, 2, 8, -9, 4, 0}

    c := make(chan int)
    go sum(s[len(s)/2:], c)
    go sum(s[:len(s)/2], c)
    x, y := <-c, <-c // 从通道 c 中接收

    fmt.Println(x, y, x+y)
}
*/

/*
package main

import "fmt"

func fibonacci(c, quit chan int) {
    x, y := 0, 1
    for {
        select {
        case c <- x:
            x, y = y, x+y
        case <-quit:
            fmt.Println("quit")
            return
        }
    }
}

func main() {
    c := make(chan int)
    quit := make(chan int)

    go func() {
        for i := 0; i < 10; i++ {
            fmt.Println(<-c)
        }
        quit <- 0
    }()
    fibonacci(c, quit)
}

*/

package main

import (
        "fmt"
        "sync"
)

func worker(id int, wg *sync.WaitGroup) {
        defer wg.Done() // Goroutine 完成时调用 Done()
        fmt.Printf("Worker %d started\n", id)
        fmt.Printf("Worker %d finished\n", id)
}

func main() {
        var wg sync.WaitGroup

        for i := 1; i <= 3; i++ {
                wg.Add(1) // 增加计数器
                go worker(i, &wg)
        }

        wg.Wait() // 等待所有 Goroutine 完成
        fmt.Println("All workers done")
}