print("hello world!")

var nums = [1, 2, 3, 4, 5]

func square(num: Int) -> Int {
    return num * num
}

for num in nums {
    print("\(num) squared is \(square(num: num))")
}
