
public class Bar extends Foo<Integer>{

  public Bar(Integer v){ super(v); }

  public Integer value() { return super.value()-1; }

}
