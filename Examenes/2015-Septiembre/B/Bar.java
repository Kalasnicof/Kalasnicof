public class Bar extends Foo{
  String tillery;

  public Bar(String t){
    this.tillery = (t+"e");
  }

  public String ricada(){
    return super.ricada()+tillery+"r";
  }
}
