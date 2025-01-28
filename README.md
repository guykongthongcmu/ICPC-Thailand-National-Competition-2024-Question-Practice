# ICPC-Thailand-National-Competition-2024-Question-Practice

Question:
A. Auntie's Magical Cake
time limit per test 1 second
memory limit per test 512 megabytes
Your aunt brings you a cake consisting of 𝑁
 pieces arranged in a straight line, labeled as cakes 1,2,3,…,𝑁
. Initially, each piece of cake has a deliciousness value of 0
. You can choose to eat the 𝑖𝑡ℎ
 piece of cake, provided that neither of its adjacent pieces has been eaten and that the 𝑖𝑡ℎ
 piece is not at the edge. Once you eat a piece of cake, it will distribute deliciousness to its adjacent pieces, keeping going until it hits the edge or its adjacent pieces have already been eaten. Once the cake distributes deliciousness to all the pieces it can, for every 𝑗𝑡ℎ
 piece that got distributed in the previous step, its deliciousness value will increase by |𝑖−𝑗|
 .

You will continue to eat cake until there are no more pieces that can be eaten under the given conditions. At that point, you can use a special ability that allows you to eat all the remaining pieces at once. Do you want to know how much deliciousness you can consume to maximize the total deliciousness of the cake?

enter any number for input:

test cases:

input 1, output 0
input 2, output 0
input 4, output 4
input 10, output 74
