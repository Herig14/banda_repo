CREATE TABLE evento (
                id BIGINT NOT NULL,
                fecha TIMESTAMP NOT NULL,
                altura DOUBLE NOT NULL,
                objeto TINYINT NOT NULL,
                CONSTRAINT evento_pk PRIMARY KEY (id)
);