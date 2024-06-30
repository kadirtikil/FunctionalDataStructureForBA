import scala.annotation.tailrec
import scala.collection.mutable.{StringBuilder, Map} 

object Main{

  def main(args: Array[String]): Unit = {
    val jsonString = """{
      "name": "John Doe",
      "age": 30,
      "email": "johndoe@example.com",
      "isMember": true,
      "balance": 100.50,
      "testtest": "testendet hier"
    }"""
    jsonParser(jsonString)
  }



  def jsonParser(jsonString: String): Unit ={
    // Check current char
    // if char is a { then an object has begun.
    // if then the char is a " or just a number, then the key has begun, and end with the char :
    // if after : the char is a { it means another object is within. otherwise if it is a " or a number 0-9 
    // then its a new key. first handle the basic cases. 

    // first the objects, a key and a value:
    // will handle datatypes later. first just get some structure in.
    //key: String = ""
    //value: String = ""
    //
    var inKey = false
    var inValue = false

    @tailrec def jsonParserHelper(text: String, key: StringBuilder = new StringBuilder, value: StringBuilder = new StringBuilder, 
      jsonMap: Map[String, String] = Map()): Unit = {
        if (text.isEmpty) {
          println("\n\n\nDONE: ")
          jsonMap.foreach(println)
          println("\n\n\n")

        } else {
          text.head match {
            case  ' ' => {
              text.tail.head match {
                case ' ' | '\n' | '"' | ')' => 
                case ch if Character.isDigit(ch) => 
                case _ => {
                  if(inKey) key.append(text.head)
                  else value.append(text.head)
                } 
              }
            }
                case '\n' =>
                case '{' => {
                  inKey = true 
                  inValue = false
                }
                case '}' =>{
                  jsonMap += (key.toString -> value.toString)
                  key.clear()
                  value.clear()
                }
                case ',' =>{
                  jsonMap += (key.toString -> value.toString)
                  key.clear()
                  value.clear()
                  inKey = true
                }
                case ':' =>{
                  inKey = false
                  inValue = true
                } 
                case _ => {
                  if (inKey) key.append(text.head)
                  else if(inValue) value.append(text.head)
                }
          }
        }
        jsonParserHelper(text.tail, key = key, value = value, jsonMap = jsonMap)
    }
    jsonParserHelper(jsonString)

    }  
}



