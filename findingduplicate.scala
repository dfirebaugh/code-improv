// To find duplicate element of list in functional way
object findingDuplicateofList {
  def duplicate[A](ls: List[A]): List[A] = ls flatMap { e => List(e, e) }
}

duplicate(List(1, 1, 1, 3, 5, 9))