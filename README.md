# System Design Products & Verticals Roadmap

## System Design Products

| Category                       | Example System                | Description                                                    | Focus / Key Considerations                                    | Common Challenges                           | Approach / Solutions                                                              |
| ------------------------------ | ----------------------------- | -------------------------------------------------------------- | ------------------------------------------------------------- | ------------------------------------------- | --------------------------------------------------------------------------------- |
| 💬 **Messaging**               | WhatsApp / Slack              | Realtime chat, delivery, encryption, scaling millions of users | Message queues, pub/sub, WebSockets, push notifications       | Ordering, delivery guarantees, offline sync | Use event-driven architecture, Kafka/RabbitMQ, message persistence, read-replicas |
| 📺 **Streaming**               | Netflix / YouTube             | Adaptive streaming, CDN, caching, ABR logic                    | Video encoding, adaptive bitrate (ABR), CDN distribution      | Latency, buffering, device differences      | Use HLS/DASH, edge caching, chunked streaming, load balancers                     |
| 🛒 **E-Commerce**              | Amazon / Flipkart             | Inventory, payments, recommendations, scalability              | Microservices, databases (SQL + NoSQL), caching, search       | Flash sales, concurrency, payment failures  | Event-driven updates, CQRS, Redis caching, transaction logging                    |
| 🕒 **Booking System**          | Zomato / Swiggy / Uber        | Realtime matching, maps, surge pricing                         | Geospatial queries, routing, queue management                 | Hotspots, overbooking, latency              | MapReduce for distance, queues for requests, real-time load balancing             |
| 💳 **Finance**                 | UPI / Paytm / Stripe          | Secure payments, reconciliation, fraud prevention              | Security (TLS/SSL), idempotency, auditing, transactions       | Fraud, double spending, reconciliation      | Two-phase commit, ledger-based accounting, anomaly detection, rate limiting       |
| 🔍 **Search**                  | Google / LinkedIn Search      | Indexing, ranking, query optimization                          | Inverted index, sharding, caching, ranking algorithms         | Scale, latency, relevance                   | Elasticsearch, distributed indexing, caching frequent queries                     |
| 📩 **Email System**            | Gmail                         | Asynchronous delivery, queuing, spam detection                 | Queues, SMTP servers, anti-spam, delivery retries             | Spam, delayed delivery, storage             | Retry queues, spam filters, message deduplication, partitioned storage            |
| 📸 **Social Media**            | Instagram / X                 | Feed generation, caching, microservices                        | Feed ranking, caching, notification systems, media storage    | High read/write ratio, personalization      | Microservices, Redis/Memcached, CDN, batch/streaming updates                      |
| 🧠 **AI-integrated Product**   | ChatGPT / Copilot / Gemini    | Request routing, model serving, caching, context mgmt          | Model inference, GPU scheduling, request batching             | Latency, scale, context management          | Load-balanced model servers, caching embeddings, vector DBs                       |
| 📊 **Analytics / BI**          | Tableau / PowerBI / Looker    | Data visualization, dashboards, reports                        | ETL pipelines, data warehouses, OLAP vs OLTP                  | Data freshness, scale, query performance    | Batch/stream pipelines, Spark/Flink, data marts, caching aggregates               |
| ☁️ **Cloud / Infrastructure**  | AWS / GCP / Azure             | Multi-tenant cloud, high availability, scaling                 | Virtualization, autoscaling, storage replication              | Downtime, cost management, failover         | IaC, autoscaling, multi-zone deployments, disaster recovery                       |
| ⚡ **Real-time / Event-driven** | Slack realtime / Trading apps | Low latency data updates                                       | WebSockets, Kafka, pub/sub, event sourcing                    | Event ordering, lost messages               | Event queues, retry mechanisms, idempotent consumers                              |
| 🔒 **Security / Privacy**      | OAuth2 / JWT-based apps       | Auth, encryption, compliance                                   | Authentication, authorization, TLS/SSL, RBAC                  | Breaches, token theft, compliance           | Encrypted storage, MFA, audit logs, rate limiting                                 |
| 📱 **Mobile / Edge**           | Uber / TikTok mobile          | Offline mode, push notifications, low latency                  | Offline caching, edge computing, battery/network optimization | Limited bandwidth, device fragmentation     | Local DBs (SQLite), background sync, edge caching                                 |
| 🛠 **DevOps / SRE**            | Kubernetes / Prometheus       | Observability, CI/CD, automated recovery                       | Metrics, logging, tracing, CI/CD pipelines                    | Failures, downtime, scaling issues          | Prometheus + Grafana, ELK stack, automated alerts, chaos testing                  |

---

### How to Use This Table for Learning

1. **Pick a category** (start small, e.g., Messaging).
2. **Understand core building blocks**:

   * Architecture, databases, caching, message queues, API patterns.
3. **Learn design patterns** relevant to it:

   * Event-driven, CQRS, microservices, etc.
4. **Practice scaling and reliability problems**:

   * High load, latency, data replication, consistency.
5. **Move to the next category** and repeat.


## **System design verticals**

*break it down verticle by verticle explaining what it is, why it’s important, and how to approach it*

---

### **1. Backend System Design**

**What:**

* Focuses on building the server-side architecture, handling requests, storing data, and ensuring scalability, reliability, and performance.
* Example project: Chaicode — a digital food delivery service.

**Why:**

* Backend is the heart of any system; it manages data, user requests, and ensures the system can handle scale and failures.
* Without a well-designed backend, apps crash under load or become slow.

**How / What to Study:**

* **Core Concepts:** Databases (SQL, NoSQL), caching (Redis, Memcached), message queues (Kafka, RabbitMQ), indexing, replication, partitioning.
* **Advanced:** Load balancing, rate limiting, retries, sharding, monitoring, logging, and tracing.
* **Design Patterns:** Microservices, monoliths, service-oriented architectures.
* **Key focus:** Reliability, performance, and maintainability.

---

### **2. Frontend System Design**

**What:**

* Design and architecture of client-side apps — websites or mobile apps.
* Example project: ChaChat — an e-commerce web app.

**Why:**

* Frontend impacts user experience, performance, and accessibility.
* Must efficiently communicate with backend while remaining responsive.

**How / What to Study:**

* **Core Concepts:** Browser rendering, React/Vue/Angular, component design, state management (Redux, Context API).
* **Advanced:** Lazy loading, code splitting, caching on client, accessibility, localization.
* **Goal:** Deliver smooth, fast, scalable, and maintainable UI.

---

### **3. AI and Machine Learning System Design**

**What:**

* Building systems for data processing, training models, and making predictions at scale.
* Example: ChatGPT-like AI models.

**Why:**

* AI/ML applications require handling large datasets efficiently and delivering predictions with low latency.
* Improves automation, personalization, and intelligent decision-making.

**How / What to Study:**

* **Core Concepts:** Data pipelines, feature engineering, model training, inference optimization.
* **Advanced:** Distributed training, GPU/TPU optimization, model versioning, monitoring accuracy and drift.
* **Goal:** Accurate, scalable, and real-time AI predictions.

---

### **4. Mobile and Edge System Design**

**What:**

* Architecture of mobile apps and edge computing solutions.
* Example: ChaChat mobile app.

**Why:**

* Mobile apps have constraints like low memory, CPU, intermittent connectivity.
* Edge computing reduces latency by processing closer to users.

**How / What to Study:**

* **Core Concepts:** Offline caching, synchronization, push notifications, local storage, security.
* **Advanced:** Optimized network usage, device-specific constraints, edge deployment strategies.
* **Goal:** Fast, responsive, and reliable mobile experiences.

---

### **5. Security and Privacy System Design**

**What:**

* Protect data in transit and at rest; manage authentication, authorization, and regulatory compliance.
* Example project: ChaPay — subscription and payment system.

**Why:**

* Security breaches damage trust and can lead to legal consequences.
* Essential for payments, personal data, and sensitive systems.

**How / What to Study:**

* **Core Concepts:** Auth frameworks (OAuth2, JWT), encryption (TLS/SSL), rate limiting, RBAC.
* **Advanced:** Monitoring suspicious activity, compliance (GDPR, HIPAA), audit logs.
* **Goal:** Safe and compliant systems.

---

### **6. Data Engineering & Analytics System Design**

**What:**

* Systems for ETL pipelines, analytics, and real-time data processing.
* Example: ChaAnalytics — dashboards and tracking user behavior.

**Why:**

* Decisions in product and business require real-time and batch data analysis.
* Ensures business intelligence and monitoring.

**How / What to Study:**

* **Core Concepts:** Kafka, Spark, Flink, batch vs stream processing, OLAP/OLTP.
* **Advanced:** Data pipelines, warehousing, dashboards, ETL orchestration.
* **Goal:** Reliable, scalable, and analyzable data flow.

---

### **7. Cloud and Infrastructure System Design**

**What:**

* Building systems on cloud platforms (AWS, GCP, Azure) with scalability and reliability.
* Example: ChaCloud — multi-tenant cloud platform.

**Why:**

* Cloud enables scaling, high availability, and disaster recovery.
* Reduces hardware maintenance and operational overhead.

**How / What to Study:**

* **Core Concepts:** Compute (EC2, Lambda), Storage (S3, GCS), Networking (VPC, CDN).
* **Advanced:** Autoscaling, failover, DR, cost optimization, monitoring.
* **Goal:** Efficient, cost-effective, and resilient infrastructure.

---

### **8. Real-Time and Streaming System Design**

**What:**

* Systems that process data with minimal delay for live updates or streaming.
* Example: ChaChat Live — live chat or live notifications.

**Why:**

* Low-latency systems are essential for chat apps, trading apps, and live video streaming.

**How / What to Study:**

* **Core Concepts:** WebSockets, Kafka, pub-sub systems, message brokers.
* **Advanced:** Event-driven architecture, horizontal scaling, fault-tolerance.
* **Goal:** Real-time, reliable data delivery.

---

### **9. Observability and Reliability System Design (SRE)**

**What:**

* Monitoring, logging, tracing, and automating recovery for systems.
* Example: ChaCloud Delivery observability.

**Why:**

* Detects failures quickly, improves uptime, and ensures smooth operations.
* Critical for production-grade systems.

**How / What to Study:**

* **Core Concepts:** Metrics (Prometheus), logging (ELK stack), tracing (Jaeger, OpenTelemetry).
* **Advanced:** Incident management, SLO/SLI/SLA, alerting, automated scaling and recovery.
* **Goal:** High reliability and maintainability.
