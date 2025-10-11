# Unified Payments Interface (UPI) — Deep System Design & Working

https://www.geeksforgeeks.org/system-design/designing-upi-system-design/

## **1. What is UPI?**

**UPI (Unified Payments Interface)** is India’s real-time payment system developed by **NPCI (National Payments Corporation of India)** under the regulation of **RBI** and **Indian Banks Association (IBA)**.

It allows users to:

* Instantly transfer money between two bank accounts using a **Virtual Payment Address (VPA)** instead of bank details.
* Do both **push (pay)** and **pull (request)** transactions.
* Operate 24×7, across all banks, including holidays.

---

## **2. Why UPI was needed**

Before UPI, digital payments used:

* **NEFT** → Batch-based, not real-time. (2–3 hrs delay)
* **RTGS** → For high-value only, not for daily use.
* **IMPS** → Real-time but required full bank details.

**Problems:**

* Required account number, IFSC, branch.
* Complicated and error-prone.
* Not interoperable between apps and banks.
* No common interface between banks.

**Goal of UPI:**
To make money transfer as easy as “sending a message”, while keeping it **secure, interoperable, and instant**.

---

## **3. Key Participants in UPI**

| Role                                | Example                    | Function                                                                      |
| ----------------------------------- | -------------------------- | ----------------------------------------------------------------------------- |
| **NPCI**                            | Infrastructure             | The *central switch* that routes all UPI transactions securely between banks. |
| **Banks**                           | ICICI, HDFC, SBI, Yes Bank | Act as either **issuer** (payer’s bank) or **acquirer** (receiver’s bank).    |
| **PSP (Payment Service Provider)**  | Yes Bank, Axis, HDFC       | Provides the connection between **apps** and **NPCI network**.                |
| **TPAP (Third Party App Provider)** | Google Pay, PhonePe, Paytm | Provides the user-facing **app interface**.                                   |
| **User (Customer/Merchant)**        | You and shopkeeper         | Initiates or receives payments using **VPA**.                                 |

---

## **4. Key Terms**

* **VPA (Virtual Payment Address):**
  Identifier like `username@bank` → maps directly to your bank account.

* **UPI ID Mapping:**
  NPCI maintains a mapping database that connects VPA ↔ Account Number + IFSC.

* **Handle:**
  The `@bank` part in VPA (e.g. `@okaxis`, `@ybl`).

* **Partner Bank:**
  Each app must tie up with at least one **PSP bank** to get into the NPCI network.

---

## **5. High-Level Flow (Simplified)**

1. **User → App (TPAP):**

   * You open Google Pay or PhonePe and create a “payment intent” (To whom, how much).

2. **App → Partner Bank (PSP):**

   * App sends this intent to its partner PSP bank (e.g. Yes Bank for PhonePe).

3. **PSP → NPCI:**

   * PSP forwards the transaction request securely to NPCI.

4. **NPCI → Receiver’s Bank (Acquirer):**

   * NPCI routes the payment to the receiver’s PSP bank (e.g. ICICI for Google Pay).

5. **Verification & Debit:**

   * NPCI requests issuer bank (payer’s) to verify PIN, check balance, and debit funds.

6. **Credit:**

   * NPCI instructs acquirer bank (receiver’s) to credit funds.

7. **Acknowledgement:**

   * Both banks acknowledge back to NPCI → then NPCI informs both PSPs → apps update user UI instantly.

---

## **6. Detailed Step-by-Step Technical Flow**

Let’s trace a payment:
**User A (PhonePe, Yes Bank)** → **User B (Google Pay, ICICI Bank)**

---

### **(1) Payment Intent Creation**

* User enters or scans VPA (e.g. `piyush@okicici`) and amount ₹1000.
* App (PhonePe) packages this into a **payment intent** with:

  ```json
  {
    "fromVPA": "user@yesbank",
    "toVPA": "piyush@okicici",
    "amount": 1000,
    "txnType": "PUSH"
  }
  ```

---

### **(2) Partner Bank Request**

* PhonePe sends this to its **partner PSP bank** — Yes Bank.
* Yes Bank verifies the request format and signs it using **digital signature** (to ensure authenticity).

---

### **(3) NPCI Transaction Routing**

* Yes Bank sends the signed transaction to NPCI via **secure channel (HTTPS + Digital Certificates)**.
* NPCI validates digital signatures and ensures the request came from a **trusted, registered PSP bank**.

---

### **(4) Identification & Routing**

* NPCI looks up the **destination VPA** (`@okicici`) → maps it to ICICI Bank.
* NPCI then forwards the request to **ICICI (Acquirer bank)**.

---

### **(5) Authorization & PIN Validation**

* NPCI sends an authorization request back to Yes Bank:
  “Authenticate this user’s payment.”

* PhonePe prompts user to **enter UPI PIN**.

  * PIN never goes to the app directly.
  * It’s encrypted using **NPCI’s UPI SDK** and sent to Yes Bank → validated by bank’s HSM (Hardware Security Module).

---

### **(6) Fund Movement**

If authentication passes:

* Yes Bank **debits** ₹1000 from the payer’s account.
* NPCI sends message to ICICI to **credit** ₹1000 to receiver’s account.

All transactions are done over **IMPS rails** (real-time settlement).

---

### **(7) Acknowledgements**

* Both banks send **ACK/NACK** (success/failure) to NPCI.
* NPCI consolidates and sends the final response to both PSPs (PhonePe, Google Pay).
* The apps show:
  ✅ “₹1000 sent successfully” / ❌ “Transaction failed”.

---

### **(8) Reversal Handling**

If:

* Debit successful ✅
* Credit failed ❌ (e.g. receiver’s bank timeout)

Then NPCI automatically **reverses the debit** by instructing issuer bank to credit back.

---

## **7. Security Layers in UPI**

| Layer                       | Mechanism                                                         |
| --------------------------- | ----------------------------------------------------------------- |
| **Encryption**              | All messages between PSP ↔ Bank ↔ NPCI are AES-256 encrypted.     |
| **Digital Signatures**      | Each PSP signs transactions to prevent tampering.                 |
| **Device Binding**          | Your phone, SIM, and account are linked to prevent misuse.        |
| **PIN Encryption**          | PIN encrypted via bank’s HSM, never stored or sent in plain text. |
| **2-Factor Authentication** | Device binding + UPI PIN = dual layer security.                   |

---

## **8. UPI Transaction Types**

1. **Push** (Pay): You send money.
2. **Pull** (Request): Merchant/app requests money from your account.

   * Used by apps like Swiggy, Zomato when you click “Pay via UPI”.
   * You approve → NPCI pulls funds from your bank.

---

## **9. Common Issues & Solutions**

| Issue                                | Cause                            | Resolution                                          |
| ------------------------------------ | -------------------------------- | --------------------------------------------------- |
| **“Money debited but not credited”** | Receiver bank didn’t acknowledge | NPCI auto-reverses after timeout (usually < 24 hrs) |
| **Transaction timeout**              | PSP or Bank API latency          | Retry via same transaction ID                       |
| **Wrong VPA**                        | Invalid mapping                  | NPCI rejects before debit                           |
| **Server load**                      | Peak-time bottlenecks            | NPCI load balances across multiple nodes            |

---

## **10. Scalability & Architecture**

* **NPCI Infrastructure:** Distributed & replicated system across data centers in India.
* **Protocol:** Uses **IMPS rails** for final settlements.
* **Real-time Acknowledgment:** Sub-1 second round trip in ideal conditions.
* **Redundancy:** Each PSP bank maintains multiple endpoints for failover.
* **Monitoring:** NPCI continuously monitors fraud, velocity checks, abnormal activity patterns.

---

## **11. Tech Stack (Probable Internal)**

Although not public, here’s an educated engineering guess:

| Layer                      | Tech Stack                                     |
| -------------------------- | ---------------------------------------------- |
| **Frontend (Apps)**        | Kotlin, Swift, React Native                    |
| **Backend PSPs**           | Java / Spring Boot, Golang                     |
| **Database**               | Oracle / PostgreSQL (for bank mapping)         |
| **Switching Layer (NPCI)** | C/C++ for low-latency routing                  |
| **Security**               | HSMs, PKI (Public Key Infra), TLS, AES         |
| **Messaging**              | ISO 8583 (Standard for financial transactions) |

---

## **12. Summary Flow Diagram (Conceptually)**

```
User → TPAP (PhonePe) → PSP Bank (Yes Bank)
     ↘                     ↘
       ↘                   ↘
          → NPCI ↔ Acquirer Bank (ICICI) → Receiver (Google Pay)
```

All secured by encryption, PIN validation, and acknowledgment chains.

---

## **13. Real Engineering Challenges**

| Problem             | How it’s solved                                                            |
| ------------------- | -------------------------------------------------------------------------- |
| **Concurrency**     | NPCI uses distributed locks and atomic operations to prevent double debit. |
| **Latency**         | Edge caching + parallel request handling in PSP servers.                   |
| **Fault tolerance** | Retry mechanism and auto-reconciliation jobs.                              |
| **Fraud detection** | Pattern detection via AI + RBI monitoring.                                 |
| **Scalability**     | Horizontal scaling using message queues and microservices.                 |

---

## **14. Evolution**

| Version            | New Features                                            |
| ------------------ | ------------------------------------------------------- |
| **UPI 1.0 (2016)** | P2P Transfers                                           |
| **UPI 2.0 (2018)** | Mandates, Overdraft, Invoice in Inbox                   |
| **UPI AutoPay**    | Subscription & recurring payments                       |
| **UPI Lite**       | Offline small-value transactions                        |
| **UPI 123PAY**     | UPI via feature phones                                  |
| **UPI Global**     | Cross-border payment integration (Singapore, UAE, etc.) |

---

## **15. Key Takeaway**

* UPI = Secure, interoperable, and real-time payment ecosystem.
* NPCI acts as the **trusted switch**.
* Apps like GPay & PhonePe are **just UI + bridge**, not money handlers.
* Partner banks and NPCI do all the real money movement.
* The design emphasizes **security, simplicity, scalability, and fault tolerance**.

---