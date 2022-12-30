# Information-Retrival
Implementing Information Retrival using Data Structures in C

![image](https://user-images.githubusercontent.com/96608251/210081851-dba18208-1a30-4c85-a9d0-aaa91001aada.png)

## Information Retrieval (IR) Model

Mathematically, models are used in many scientific areas having objective to understand some phenomenon in the real world. A model of information retrieval predicts and explains what a user will find in relevance to the given query. IR model is basically a pattern that defines the above-mentioned aspects of retrieval procedure and consists of the following −

    A model for documents.

    A model for queries.

    A matching function that compares queries to documents.

Mathematically, a retrieval model consists of −

D − Representation for documents.

R − Representation for queries.

F − The modeling framework for D, Q along with relationship between them.

R (q,di) − A similarity function which orders the documents with respect to the query. It is also called ranking.

## User Query Improvement

The primary goal of any information retrieval system must be accuracy − to produce relevant documents as per the user’s requirement. However, the question that arises here is how can we improve the output by improving user’s query formation style. Certainly, the output of any IR system is dependent on the user’s query and a well-formatted query will produce more accurate results. The user can improve his/her query with the help of relevance feedback, an important aspect of any IR model.
