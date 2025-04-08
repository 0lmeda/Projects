# 🔐 **Encryption Project**

## 📘 Description  
This is a **basic encryption project** that uses the **XOR encryption method**.  
It takes a password, encrypts it using a key, and saves the encrypted result into a `.txt` file.  
You can also decrypt the data by loading it from the file and applying XOR again.

---

## 🧠 How It Works

### ✨ What is XOR Encryption?

**XOR** (Exclusive OR) is a simple but powerful encryption technique.

- It compares bits (1s and 0s) of characters from the **password** and the **key**.
- If the bits are **the same**, it gives `0`.
- If the bits are **different**, it gives `1`.

🧩 You can **decrypt** the result using the same XOR process again — it's reversible!

---

## 🧾 Code Explanation

### 🔐 `encrypt` Function

```cpp
string encrypt(const string pass, const string key) {
    string result = pass;
    for (size_t i = 0; i < pass.size(); i++) {
        result[i] = pass[i] ^ key[i % key.size()];
    }
    return result;
}
