object P21 {
  def insertAt[A](e: A, n: Int, ls: List[A]): List[A] = ls.splitAt(n) match {
    case (pre, post) => pre ::: e :: post
  }
}

insertAt(toinsert, 1, List(a, b, c, d))