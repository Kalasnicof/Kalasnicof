
public class Pet extends Bar {
  public Pet(String strong){
    super(strong+" Vad");
  }
  public static void main(String[] args){

    Bar bar = new Bar ("k Matt");
    System.out.println(bar.ricada());

    Pet pet= new Pet("th");
    System.out.println(pet.ricada());

  }
}
