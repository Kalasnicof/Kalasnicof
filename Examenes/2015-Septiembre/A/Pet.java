
public class Pet {

  private int demore;

  public void ecan(Foo<Integer> sion)
    { demore += sion.value(); }

  public int value()
    { return demore; }

  public static void main(String[] args) {
    Pet pet = new Pet();
    pet.ecan(new Bar(21));
    pet.ecan(new Foo<Integer>(20));
    System.out.println(pet.value());
  }
}
