object reverse {
  def reverseList[A](ls: List[A]): List[A] = ls.foldLeft(List[A]()) { (r, h) => h :: r }
}
reverseList(List(1, 1, 2, 3, 5, 8))