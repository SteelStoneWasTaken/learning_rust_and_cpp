use std::sync::Mutex;

static MUX: Mutex<i32> = Mutex::new(0);

#[no_mangle]
pub extern "C" fn duplicar(x: i32) {
    *MUX.lock().unwrap() += 1;
    println!("rust: {}", x + *MUX.lock().unwrap());
}

#[no_mangle]
pub extern "C" fn retornar() -> i32 {
    return *MUX.lock().unwrap();
}