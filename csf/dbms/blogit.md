Users
- Username
- Password
- First name
- Last name
- Email address



CREATE TABLE IF NOT EXISTS "auth_user" (
    "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
    "password" varchar(128) NOT NULL,
    "last_login" datetime NULL,
    "is_superuser" bool NOT NULL,
    "username" varchar(150) NOT NULL UNIQUE,
    "last_name" varchar(150) NOT NULL,
    "email" varchar(254) NOT NULL,
    "is_staff" bool NOT NULL,
    "is_active" bool NOT NULL,
    "date_joined" datetime NOT NULL,
    "first_name" varchar(150) NOT NULL);

CREATE TABLE IF NOT EXISTS "blog_blogauthor" (
    "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
    "bio" text NULL,
    "location" varchar(30) NULL,
    "date_of_birth" date NULL,
    "date_of_death" date NULL,
    "user_id" integer NULL UNIQUE REFERENCES "auth_user" ("id") DEFERRABLE INITIALLY DEFERRED);

CREATE TABLE IF NOT EXISTS "blog_blogcategory" ("name" varchar(32) NOT NULL PRIMARY KEY);

CREATE TABLE IF NOT EXISTS "blog_blogpost" (
    "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
    "title" varchar(100) NOT NULL,
    "description" text NOT NULL,
    "post_date" date NOT NULL,
    "author_id" bigint NULL REFERENCES "blog_blogauthor" ("id") DEFERRABLE INITIALLY DEFERRED);

CREATE TABLE IF NOT EXISTS "blog_blogpost_categories" (
    "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
    "blogpost_id" bigint NOT NULL REFERENCES "blog_blogpost" ("id") DEFERRABLE INITIALLY DEFERRED,
    "blogcategory_id" varchar(32) NOT NULL REFERENCES "blog_blogcategory" ("name") DEFERRABLE INITIALLY DEFERRED);

CREATE TABLE IF NOT EXISTS "blog_blogcomment" (
    "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
    "text" text NOT NULL,
    "comment_date" datetime NOT NULL,
    "author_id" bigint NULL REFERENCES "blog_blogauthor" ("id") DEFERRABLE INITIALLY DEFERRED,
    "blog_id" bigint NOT NULL REFERENCES "blog_blogpost" ("id") DEFERRABLE INITIALLY DEFERRED);

CREATE INDEX "blog_blogpost_author_id_ffcc150f" ON "blog_blogpost" ("author_id");

CREATE UNIQUE INDEX "blog_blogpost_categories_blogpost_id_blogcategory_id_a64d32c5_uniq" ON "blog_blogpost_categories" ("blogpost_id", "blogcategory_id");

CREATE INDEX "blog_blogpost_categories_blogpost_id_daeea608" ON "blog_blogpost_categories" ("blogpost_id");

CREATE INDEX "blog_blogpost_categories_blogcategory_id_f6695246" ON "blog_blogpost_categories" ("blogcategory_id");

CREATE INDEX "blog_blogcomment_author_id_ce11ddad" ON "blog_blogcomment" ("author_id");

CREATE INDEX "blog_blogcomment_blog_id_d3b167d7" ON "blog_blogcomment" ("blog_id");

CREATE TABLE IF NOT EXISTS "django_session" ("session_key" varchar(40) NOT NULL PRIMARY KEY, "session_data" text NOT NULL, "expire_date" datetime NOT NULL);

CREATE INDEX "django_session_expire_date_a5c62663" ON "django_session" ("expire_date");

CREATE TABLE IF NOT EXISTS "blog_userfollowing" (
    "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
    "followed_at" datetime NOT NULL,
    "follower_user_id_id" integer NOT NULL REFERENCES "auth_user" ("id") DEFERRABLE INITIALLY DEFERRED,
    "following_user_id_id" integer NOT NULL REFERENCES "auth_user" ("id") DEFERRABLE INITIALLY DEFERRED,
    CONSTRAINT "unique_user_following" UNIQUE ("follower_user_id_id", "following_user_id_id"));

CREATE INDEX "blog_userfollowing_follower_user_id_id_2c65d8cb" ON "blog_userfollowing" ("follower_user_id_id");

CREATE INDEX "blog_userfollowing_following_user_id_id_fa2a866c" ON "blog_userfollowing" ("following_user_id_id");
