package recfun
import common._

import scala.collection.mutable.ListBuffer

object Main {
  def main(args: Array[String]) {
    println("Pascal's Triangle")
    for (row <- 0 to 10) {
      for (col <- 0 to row)
        print(pascal(col, row) + " ")
      println()
    }
  }

  /**
   * Exercise 1
   */
  def pascal(c: Int, r: Int): Int = if (c == 0 || r == c) 1 else pascal(c - 1, r - 1) + pascal(c, r - 1)

  /**
   * Exercise 2
   */
  def balance(chars: List[Char]): Boolean = {
    val backlog = new ListBuffer[Char]()

    def balanceIter(backlog: ListBuffer[Char], chars: List[Char]): Boolean = {
      if (chars.isEmpty) isBalanced
      else {
        balanceIter(addParenthesis(chars.head), chars.tail)
      }
    }

    def addParenthesis(par: Char): ListBuffer[Char] = {
      if (par == '(' || par == ')') backlog += par

      if (backlog.length > 1 && (backlog.apply(backlog.length - 2) == '(' && backlog.apply(backlog.length - 1) == ')'))
        backlog.remove(backlog.length - 2, 2)
      backlog
    }

    def isBalanced = backlog.isEmpty

    balanceIter(backlog, chars)
  }

  /**
   * Exercise 3
   */
  def countChange(money: Int, coins: List[Int]): Int = {

    val m = money

    def countIter(money: Int, coins: List[Int]): Int = {
      if (!coins.isEmpty) {
        if (money > 0)
          if((money - coins.head) > 0)
            countIter(money - coins.head, coins) + countIter(money, coins.tail)
          else if((money - coins.head) == 0)
            1 + countIter(money, coins.tail)
          else
            countIter(money, coins.tail)
        else if (money == 0)
          1 + countIter(m, coins.tail)
        else
          countIter(m, coins.tail)
      } else {
        0
      }
    }
    countIter(m, coins)
  }

}
