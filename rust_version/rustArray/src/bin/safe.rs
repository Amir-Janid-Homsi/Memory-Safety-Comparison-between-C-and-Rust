use std::io;
use std::io::Write;

fn main() 
{
    loop
    {
        let mut input = String::new();
        println!("\nMemory Safety Bug Runner\n");
        println!("1. Use-After-Free");
        println!("2. Double Free");
        println!("3. Buffer Overflow");
        println!("4. Exit");
        print!("Choice: ");
        std::io::stdout().flush().unwrap();
        io::stdin().read_line(&mut input).unwrap();
        let choice: i32 = input.trim().parse().unwrap_or(-1);
        match choice
        {
            1 =>
            {
                let mut vector = vec![10, 20];
                let ptr = vector.as_mut_ptr();
                drop(vector);
                println!("{}", *ptr);  // no unsafe == rust refuses to compile
            }
            2 =>
            {
                let mut vector = vec![0, 0];
                let ptr = vector.as_mut_ptr();
                let oldVectorLength = vector.len();
                let oldVectorCapacity = vector.capacity(); 
                drop(vector);
                let firstVec = Vec::from_raw_parts(ptr, oldVectorLength, oldVectorCapacity);  // no unsafe == rust refuses to compile
                drop(firstVec);
            }
            3 =>
            {
                let mut vector = vec![0, 0];
                let ptr = vector.as_mut_ptr();
                *ptr.add(2) = 999; // no unsafe == rust refuses to compile
                drop(vector);
            }
            4 =>
            {
                println!("Goodbye.");
                return;
            }
            _ =>
            {
                println!("Invalid choice.");
            }
        }
    }
}
