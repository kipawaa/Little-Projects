module Main where

-- fibonacci function
fibonacci 0 = 1
fibonacci 1 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)

-- main loop
main = do 
        putStrLn "pick a number! :"
        x <- readLn
        putStrLn (show (fibonacci x) ++ " is the " ++ show x ++ "th fibonacci number!")

