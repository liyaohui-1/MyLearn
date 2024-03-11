# C++11新特性
## 1.long long类型
long long 类型是C++ 11 中新定义的。
## 2.列表初始化
作为C++11新标准的一部分，用花括号来初始化变量得到了全面应用，而在此之前，这种初始化的形式仅在某些受限的场合下才能使用。
>注意：初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，而以一个新值来替代。
## 3.nullptr
C++11新标准下，初始化指针最好使用nullptr。
>原因：因为C++会将0和NULL，这取决于编译器如何去定义NULL,有的会定义为(void*)0,有的会定义为0；C++不允许将void*隐式转换为其他类型，在C++重载时会发生混乱。如：
- ``` void foo(char*)```
- ``` void foo(int)    ```
- 如果NULL被定义为void* ,那么当编译 ```char* ch = NULL```时，当```foo(NULL)```时，此时NULL为0，会去调用```foo(int)```,从而发生混乱。
为解决问题，需要区分NULL和0，故使用nullptr代替NULL,nullptr的类型为nullptr,可以转换为任何指针和成员指针的类型，也可以进行相等或不等的比较。
## 4.constexpr变量
C++11新标准规定，运行将变量声明为**constexpr**类型以便由编译器来验证变量的值是否是一个常量表达式。声明为constexpr的变量一定是一个常量，并且必须用常量表达式初始化。
- **一般来说**：如果你认定变量时一个常量表达式，那就把它声明成constexpr类型。
## 5.类型别名
类型别名是一个名字，它是某种类型的同义词。使用类型别名的好处，可以让复杂的类型名字变简单明了，还有助于程序员使用该类型的真实目的。
## 6.auto类型说明符
能让表达式代替我们去分析表达式所属的类型。
## 7.decltype类型指示符
有时会遇到这种情况：希望从表达式的类型推断出要定义的变量的类型，但是不想用该表达式的值初始化变量。
这时，C++11引入了第二种类型说明符**decltype**,它的作用是**选择并返回操作数的数据类型**，在此过程中，编译器分析表达式并得到他的类型，却不计算实际表达式的值。
* 注意：decltype中如果是表达式，表达式的内容是解引用，则得到的类型为引用类型。**decltype((variable))**:得到的永远是引用类型,而**decltype(variable)** 只有当variable本身是一个引用时才引用。
## 8.类内初始化
>C++11新标准规定，可以为成员变量提供一个**类内初始值**。创建对象时，类内初始值将用于初始化数据成员。没有初始值的成员将被默认初始化。
## 9.使用atuo或decltype缩写类型
允许编译器通过auto或decltype推断变量类型
## 10.范围for语句
```
    for( declaration: expression)
        statement
    其中，expression部分是一个对象，用于表示一个序列。declaration部分负责定义一个变量，该变量将被用于访问序列中的基础元素。每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值。
```
## 11.定义vector对象的vector(向量的向量)
>在早期版本的C++标准中，如果vector的元素还是vector(或者其他模板类型)，则其定义的形式与现在的C++11新标准略有不同。过去，必选在外层vector对象的右尖括号和其元素类型之间增加一个空格，例如```vector<vector<int> >```,而非```vector<vector<int>>```。
## 12.vector的列表初始化
C++11新标准还提供了另外一种为vector对象赋初值的方法，即列表初始化。使用花括号括起来0个或多个初始元素值赋给vector对象。
- 例如：```vector<string> articles ={"a","an","the"};```
## 13.容器的cbegin()和cend()函数
如果对象只需读操作而无须写操作的话最好使用常量类型(比如const_iterator)。为了便于得到const_iterator类型的返回值,C++11新标准引入了两个新函数，分别是cbegin和cend:
```
vector<int> v;
const vector<int> cv;
auto it1 = v.begin();   //it1的类型是vector<int>::iterator
auto it2 = cv.begin();  //it2的类型是vector<int>::const_iterator
auto it3 = v.cbegin();  //it3的类型是vector<int>::const_iterator
```
类似于begin和end,上述两个新函数也分别返回指示容器第一个元素或最后元素下一个位置的迭代器。有所不同的是，不论vector对象的迭代器(或string对象)本身是否是常量，返回值都是const_iterator。
## 14.标准库函数begin()和end()
C++11新标准引入了两个名为begin和end的函数，这两个函数与容器中的两个同名成员功能类似，不过数组毕竟不是类类型，因此这两个函数不是成员函数。正确的使用形式是将数组作为它们的参数,见源文件对应代码。
## 15.使用auto和decltype简化声明
随着C++11新标准的提出，通过使用auto或者decltype就能尽可能地避免在数组前面加上一个指针类型了。
## 16.除法的舍入规则
在除法运算中，如果两个运算对象的符号相同则商为正(如果部位0的话)，否则商为负。C++语言的早期版本允许结果为负值的商向上或向下取整,C++11新标准则规定商一律向0取正(即直接切除小数部分)。
```
例如:
    (-m)/n和m/(-n)都等于-(m/n);m%(-n)等于m%n,(-m)%n等于-(m%n)。
```
## 17.用大括号包围的值列表赋值
C++11新标准允许使用花括号括起来的初始值列表作为赋值语句的右侧运算符。
## 18.将sizeof用作类成员
C++11新标准允许我们使用作用域运算符来获取类成员的大小。
## 19.范围for语句
不能通过范围for语句增加vector对象(或其它容器)的元素，在范围for语句中，预存了end()的值。一旦在序列中添加(删除)元素，end函数的值就可能变得无效了。
## 20.标准库initializer_list类
当处理含有可变形参的函数时，C++11提供了两种主要方法：如果所有形参的类型相同，可以传递一个名为initializer_list的标准库类型；如果类型不同，则可以使用函数模板。
使用initializer_list类需要保护同名头文件。
## 21.列表初始化返回值
C++11新标准规定，函数可以返回花括号包围的值的列表。
## 22.定义尾置返回类型
C++11新标准为了简化函数返回值类型，使用**尾置返回类型**。任何函数的定义都能够使用尾置返回，但是这种形式对于返回类型比较复杂的函数最有效，比如返回类型是数组的指针或数组的引用。尾置返回类型跟在形参列表后面并以一个->符号开头。为了表示函数真正的返回类型跟在形参列表之后，我们在本应出现返回类型的地方放置一个atuo:
```例如：
    //func接受一个int类型的实参，返回一个指针，该指针指向含有十个整形的数组
    auto func(int i) -> int(*)[10];
```
## 23.使用decltype简化返回类型定义
使用例子见源文件
## 24.constexpr函数
constexpr函数是指能用于常量表达式的函数。定义constexpr函数的方法与其他函数类似，不过要遵循几项约定：函数的返回类型和形参的类型都得是字面值类型，而且函数体中有且只有一条return语句。
执行constexpr函数时，编译器把对constexpr函数的调用替换成结果值。为了能在编译过程中随时展开，constexpr被隐式地指定为内联函数。
- **注意:**内联函数和constexpr函数的定义需要放在头文件中。**原因**:内联函数和constexpr可以在程序中多次定义。毕竟，编译器要想展开函数仅有声明是不够的，还需要函数的定义。不过，对于某个给定的内联函数或者constexpr函数来说，它的多个定义必须完全一致。
## 25.使用=default生成默认构造函数
C++11新标准中，如果我们需要默认的行为，那么可以在参数列表后面加上 **=default**来要求编译器生成构造函数。
## 26.类对象成员的类内初始化
对类内部需要设置默认值的成员变量进行类内初始化。
## 27.委托构造函数
C++11新标准扩展了构造函数初始值的功能，使得我们可以定义所谓的**委托构造函数**。一个委托构造函数使用它所属类的其它构造函数执行它自己初始化过程，或者说它把它自己的一些(或者全部)职责委托给了其它构造函数。
和其他构造函数一样，一个委托构造函数也有一个成员初始值的列表和一个函数体。在委托构造函数内，成员初始值列表只有一个唯一的入口，就是类名本身。和其他成员初始值一样，类名后面紧跟圆括号括起来的参数列表，参数列表必须与类中另外一个构造函数匹配。
例子如下:
```
    class Sales_data{
        public:
            // 非委托构造函数使用对应的实参初始化成员
            Sales_data(std::string s,unsigned cnt,double price):
            bookNo(s),units_sold(cnt),revenue(cnt*price) {}
            // 其余构造函数全部委托给另外一个构造函数
            Sales_data():Sales_data(" ",0,0) {}
            Sales_data(std::string s):Sales_data(s,0,0) {}
            Sales_data(std::istream &is):Sales_data()
                                                { read(is, *this); }
        private:
            std::string bookNo;
            unsigned units_sold;
            double revenue;
    };
```
当一个构造函数委托给另一个构造函数时，受委托的构造函数的初始值列表和函数体被依次执行。在Sales_data类中，受委托的构造函数体内恰好是空的。加入函数体包含有代码的话，将先执行这些代码，然后控制权才会交还给委托者的函数体。
## 28.constexpr构造函数
constexpr构造函数用于生成constexpr对象以及constexpr函数的参数或返回类型。
例如
```
    class Debug{
        public:
            constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
            constexpr Debug(bool h,bool i,bool o):
                        hw(h), io(i), other(o) { }
            constexpr bool any() { return hw||io||other;}
            void set_io(bool b) {io = b;}
            void set_hw(bool b) {hw = b;}
            void set_other(bool b) {other = b;}

        private:
            bool hw;    //硬件错误
            bool io;    //io错误
            vool other; //其他错误
    }

    int main()
    {
        constexpr Debug io_sub(false, true, false);     // 调试IO
        if(io_sub.any())                                // 等价于if(true)
            cerr << "print appropriate error message" << endl;
        constexpr Debug prod(false);                    // 无调试
        if(prod.any())                                  // 等价于if(false)
            cerr << "print an error message" << endl; 

        return 0;
    }
    
```
## 29.用string对象处理文件名
C++11新标准中，文件名既可以是库类型string对象，也可以是C风格字符串。
## 30.array和forward_list容器
array(固定大小的数组)和forward_list(单向链表)是新C++新标准增加的类型。与内置数组相比,array是一种更安全、更容易使用的数组类型。与内置数组类型，array对象的大小是固定的。因此，array不支持添加和删除元素以及改变容器大小的操作。forward_list的设计目标是达到与最好的手写的单向链表数据结构相当的性能。因此，forward_list没有size操作，因为保存或计算大小就会比手写链表多出额外的开销。
## 31.容器的cbegin和cend函数
当不需要写访问时，应使用cbegin和cend。
例如：
```
    list<string> a = {"Milton", "Shakespeare", "Austen"};
    list<string>::const_iterator it6 = a.cbegin();
```
## 32.容器的列表初始化
在新标准中，我们可以对一个容器进行列表初始化。
例：
```
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};
```
## 33.容器的非成员函数swap
在C++11新标准库中，容器既提供成员函数版本的swap,也提供非成员版本的swap。统一使用非成员版本的swap是一个好习惯。
## 34.容器insert成员的返回值
在新标准下，接受元素个数或范围的insert版本返回指向第一个新加入元素的迭代器。
## 35.容器的emplace成员
新标准引入了三个新成员-emplace_front、empalce_back和emplace，这些操作构造而不是拷贝元素。这些操作分别对应push_front、push_back和insert。运行我们将元素放在头部、尾部或者一个指定位置。
当调用push或insert成员函数时，我们将元素类型的对象传递给它们，这些对象被拷贝到容器当中。而当我们调用一个emplace成员函数时，则是将参数传递给元素类型的构造函数。emplace成员使用这些参数在容器管理的内存空间中直接构造元素。
```
    //在c的末尾构造一个Sales_data对象
    //使用三个参数的Sales_data构造函数
    c.emplace_back("978-0590353403",15,15.99);
    //错误，没有接受三个参数的push_back版本
    c.push_back("978-0590353403",15,15.99);
    //正确，创建一个临时的Sales_data对象传递给push_back
    c.push_back(Sales_data("978-0590353403",15,15.99));
```
## 36.shrink_to_fit
在新标准库中，我们可以调用shrink_to_fit函数来要求容器退回不需要的内存空间。size和capacity不相等时，capacity多余出来的空间。
## 37.string的数值转换表达式
新标准引入了多个函数，可以实现数组数据与标准库string之间的转换
```
    int i = 42;
    string s =to_string(i); //将整数i转换为字符串表现形式
    double d = stod(s);     //将字符串s转换为浮点数
```
## 38.lambda表达式
到目前为止，我们使用过的仅有两种可调用对象势函数和函数指针。还有其他两种可调用的对象：重载了函数调用运算符的类，以及**lambda表达式**。
一个lambda表达式表示一个可调用的代码单元。我们可以将其理解为一个未命名的内联函数。与任何函数类似，一个lambda具有一个返回类型、一个参数列表和一个函数体。但与函数不同，lambda可能定义在函数内部。一个lambda表达式具有如下形式：

```[capture list](parameter list) -> return type[function body]```
其中，capture list(捕获列表)是一个lambda所在函数中定义的局部变量的列表(通常为空);return type、parameter list和function body与任何普通函数一样，分别表示返回类型、参数列表和函数体。但是，与普通函数不同。lambda必须使用尾置返回来指定返回类型。
注意：1. 如果lambda的函数体包含任何单一return语句之外的内容，且未指定返回类型，则返回void。
     2. lambda不能有任一参数
     3. lambda表达式能在函数中定义函数，并且可以使用```[]```捕获函数内部使用的局部变量，捕获方式有两种：分别是值捕获和引用捕获，值捕获不会修改捕获后的局部变量值，引用捕获会改变捕获的局部变量的值。
## 39.lambda表达式中的尾置返回类型
当我们需要为一个lambda定义返回类型时，必须使用尾部返回类型。
## 40.标准库bind函数
bind是标准库函数，它定义在头文件functionl中。可以将bind函数看做一个通用的函数适配器，它接受一个可调用的对象，生成一个新的可调用对象“适应”原对象的参数列表。
调用bind的一般形式为：
```auto newCallable = bind(callable,arg_list)```
其中，newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的callable的参数。即，当我们调用newCallable时，newCallable会调用callable，并传递给它arg_list中的参数。
arg_list中的参数可能包含形如_n的名字，其中n是一个整数。这些参数事“占位符”，表示newCallable的参数，它们占据了传递给newCallable的参数的“位置”。数值n表示生成的可调用对象中参数的位置:_1为newCallable的第一个参数，_2为第二个参数，依次类推。
## 41.关联容器的列表初始化
在新标准下，我们也可以对关联容器进行值初始化。
```
    map<string,string> authors = {{"Joyce","James"},
                                  {"Austen","Jane"},
                                  {"Dickens","Charles"}};
```
## 42.列表初始化pair的返回类型
在新标准下，我们可以对返回值进行列表初始化。
```
    pair<string,int> process(vector<string> &v)
    {
        //处理v
        if(!v.empty())
            return {v.back(),v.back().size()};
        else
            return pair<string,int> ();
    }
```
## 43.pair的列表初始化
在新标准下，创建一个pair最简单的方法是在参数列表中使用花括号初始化。也可以调用make_pair或显式构造pair。一个insert调用中的参数
```
    //向word_count插入word的四种方法
    word_count.insert({word,1});
    word_count.insert(make_pair(word,1));
    word_count.insert(pair<string,size_t> (word,1));
    word_count_insert(map<string,size_t>::value_type(word,1));

```
## 44.无序关联容器
新标准定义了4个无序关联容器。
## 45.智能指针
智能指针是一个类模板，将指针封装起来，为了解决内存泄漏的问题，在对象生命周期结束时释放内存。
新的标准库提供了两种**智能指针**类型来管理动态对象。智能指针的行为类似常规指针，重要的区别是它负责自动释放所指向的对象。
新标准库提供的这两种智能指针的区别在于管理底层指针的方式：**shared_ptr**允许多个指针指向同一个对象；**unique_ptr**则“独占”所指向的对象。标准库还定义了一个名**weak_ptr**的伴随类，它是一种弱引用，指向shared_ptr所管理的对象。这三种类型都定义在memory头文件中。
## 46.shared_ptr类
因为智能指针也是模板，因此，当创建一个智能指针时，必须提供额外得信息——指针可以指向的类型。
```
    shared_ptr<string>    p1;  //shared_ptr，可以指向string
    shared_ptr<list<int>> p2;  //shared_ptr，可以指向int的list
```
## 47.动态分配内存的列表初始化
默认情况下，动态分配的对象时默认初始化的，这意味着内置类型或组合类型的对象的值将是未定义的，而类类型对象将用默认构造函数进行初始化：
```
    string ps = new string; //初始化为空string
    int *pi =new int; //pi指向一个未初始化的int
```
可以使用直接初始化方式来初始化一个动态分配的对象。可以使用传统的构造方式(使用圆括号)，在新标准下，也可以使用列表初始化(使用花括号)：
```
    int *pi = new int(1024);    //pi指向的对象的值为1024
    string *ps = new string(10,'9');    //*ps为"9999999999"
    vector<int> *pv = new vector<int> {0,1,2,3,4,5,6,7,8,9};
``` 
## 48.auto和动态分配
可以提供一个括号包围的初始化器，就可以使用auto从此初始化器来推断要分配的对象的类型。但是，由于编译器要用初始化器的类型来推断要分配的类型，只有当括号中仅有单一初始化器时才可以使用auto:
```
    auto p1 = new auto(obj);    //p指向一个与obj类型相同的对象，该对象用obj进行初始化
    auto p2 = new auto{a,b,c};  //错误：括号中只能有单个初始化器
```
p1的类型是一个指针，指向从obj自动判断出的类型。若obj是一个int，那么p1就是int*;若obj是一个string,那么p1是一个string*；依次类推。新分配的对象用obj的值进行初始化。
## 49.unique_ptr类
一个unique_ptr“拥有”它所指向的对象。与shared_ptr不同，某个时刻只能有一个unique_ptr指向一个给定对象。当unique_ptr被销毁时，它所指向的对象也被销毁。
## 50.weak_ptr类
weak_ptr是一种不控制所指向对象生存期的智能指针，它指向由一个shared_ptr管理的对象。将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数。一旦最后一个指向对象的shared_ptr被销毁，对象就会释放。即使有weak_ptr指向对象，对象也还是会被释放，因此,weak_ptr的名字抓住了这种智能指针“弱”共享对象的特点。
## 51.范围for语句不能用于动态分配数组
**分配一个数组会得到一个元素类型的指针**
```
    int *p = new int[42];
```
如上述，当用new分配一个数组时，我们并未得到一个数组类型的对象，而是得到一个数组元素类型的指针。即使我们使用类型别名定义了一个数组类型，new也不会分配一个数组类型的对象。
由于分配的内存并不是一个数组类型，因此不能对动态数组调用begin或end。
## 52.动态分配数组的列表初始化
## 53.auto不能用于分配数组
## 54.allocator::construct可使用任意构造函数
标准库allocator类定义在头文件memory中，它帮助我们将内存分配和对象构造分离开来。
## 55.将=default用于拷贝控制成员
我们可以通过将拷贝控制成员定义为=default来显式地要求编译器生成合成的版本。
```
class  Sales_data{
    public:
        //拷贝控制成员；使用default
        Sales_data()=default;
        Sales_data(const Sales_data&)=default;
        Sales_data& operator=(const Sales_data&);
        ~Sales_data()=default;
        //其它成员的定义，略
};
Sales_data& Sales_data::operator=(const Sales_data&)=default;
```
当我们在类内使用=default修饰成员的声明时，合成的函数将隐式地声明为内联的(就像其它类内声明的成员函数一样)。如果我们不希望合成的函数是内联函数，应该只对成员的类外定义使用=default，就像对拷贝赋值运算符所做的那样。
Note:只能对具有合成版本的成员函数使用=default(即，默认构造函数或拷贝控制成员)。
## 56.使用=delete阻止拷贝类对象
如果需要禁止拷贝构造函数和拷贝赋值运算符，在新标准下，可以通过将拷贝构造函数和拷贝赋值运算符定义为**删除的函数(deleted function)** 来阻止拷贝。删除的函数是这样一种函数：虽然对其进行了声明，但不能以任何方式使用它们。在函数得参数列表后面加上=delete指出将它定义为删除的：
```
    struct NoCopy{
        NoCopy()=default;    //使用合成的默认构造函数
        NoCopy(const NoCopy&)=delete;   //阻止拷贝
        NoCopy& operator=(const NoCopy&)=delete;    //阻止赋值
        ~NoCopy()=default;  //使用合成的析构函数
    };
```
## 57.用移动类对象代替拷贝类对象
使用移动构造函数实现。是避免频繁调用拷贝构造调用的，新标准提供了两种方法，一种是移动构造函数，一种是名为**move**的标准库函数。
## 58.右值引用
为了支持移动操作，新标准库引入了一种新的引用类型——**右值引用**。所谓右值引用就是必须绑定到右值的引用。我们通过&&而不是通过&来获得右值引用。右值引用有一个重要的性质——只能绑定到一个将要销毁的对象。
**左值持久；右值短暂**
左值有持久的状态，而右值要么是字面常量，要么是在表达式求值过程中创建的临时对象。
由于右值引用只能绑定到临时对象，我们得知
>·该引用对象将要被销毁

>·该对象没有其他用户

这两个特性意味着：使用右值引用的代码可以自由地接管所引用对象的资源。
Note：右值引用指向将要被销毁的对象。因此，可以从绑定到右值引用的对象“窃取”状态。
## 59.标准库move函数
虽然不能将一个右值引用直接绑定到一个左值上，但可以显式地将一个左值转换为对应的右值引用类型。可以通过调用一个名为**move**的新标准库函数来获得绑定到左值上的右值引用，此函数定义在头文件utility中。使用move之后，之前的对象可以赋值和销毁，但不能再使用它。
## 60.移动构造函数和移动赋值
移动构造函数类似拷贝构造函数，移动构造函数的参数也只有一个，为该类型的常引用，但是为右值引用。
## 61.移动构造函数通常应该是noexcept
noexcept是我们承诺一个函数不抛出异常的一种方法。在一个函数的参数列表后指定noexcept。在一个构造函数中，noexcept出现在参数列表和初始化列表开始的冒号之间。
```
class StrVec{
    public:
        StrVec(const StrVec&& other) noexcept;//移动构造函数
};
```
Note:不抛出异常的移动构造函数和移动赋值运算符必须标记为noexcept。
## 62.移动迭代器
新标准库中定义了一种**移动迭代器**适配器。一个移动迭代器通过改变给定迭代器的解引用运算符的行为来适配此迭代器。一般来说，一个迭代器的解引用运算符返回一个指向元素的左值。与其他迭代器不同，移动迭代器的解引用运算符生成一个右值引用。
通过调用标准库的make_move_iterator函数将一个普通迭代器转换为一个移动带去。此函数接受一个迭代器参数，返回一个移动迭代器。
## 63.引用限定成员函数
this的左值/右值属性的方式与定义const成员函数相同，即，在参数列表后放置一个**引用限定符**。
```
class Foo{
    public:
        Foo& operator=(const Foo&) &;//只能向可修改的左值赋值
    //Foo的其它参数
};
Foo& Foo::operator=(const Foo& rhs) &
{
    //执行将rhs赋予本对象所需的工作
    return *this;
}
```
## 64.function类模板
见day10
## 65.explicit类型转换运算符
C++11新标准引入了**显式地类型转换运算符**
```
class SmallInt{
    public:
        SmallInt(int i = 0):val(i)
        {
            if(i < 0 || i > 255)
                throw std::out_of_range("Bad SmallInt Value");
        }
        //编译器不会自动执行这一类型的转换
        //这里有一个语法：operator T()，实现重载隐式转换，将返回值隐式转换为T类型
        explicit operator int() const {return val;} 
    private:
        std::size_t val;
}
SmallInt si = 3; //正确：SmallInt的构造函数不是显式转换的
si + 3; //错误：此处需要隐式地类型转换，蛋类的运算符要求是显式的
static_cast<int>(si) + 3;   //正确：显式地请求类型转换
```
