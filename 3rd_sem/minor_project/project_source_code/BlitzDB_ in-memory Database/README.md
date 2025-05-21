# BlitzDB  

BlitzDB is a simple, in-memory data store inspired by Redis. It supports basic key-value operations, sorted set operations, and time-to-live (TTL) functionality for keys.  

## Features  
- Key-Value Store: `SET`, `GET`, and `DEL` commands.  
- Sorted Set Operations: `ZADD` and `ZSCORE`.  
- Time-to-Live (TTL): Assign expiration times to keys.  

## Getting Started  

### Prerequisites  
- C++ compiler with POSIX support.  
- Make utility for building the project.  

### Installation  
1. Clone the repository:  
   ```bash  
   git clone https://github.com/your-username/blitzdb.git  
   cd blitzdb  
