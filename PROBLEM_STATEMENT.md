# 📝 صورت تمرین: مدیریت باغ‌وحش

> این تمرین در دو گام طراحی شده و بخشی از تمرین پنجم درس **مبانی برنامه‌سازی** است.

---

## گام یک — طراحی ساختار و دستورهای پایه

امین مسئول نگهداری حیوانات یک باغ‌وحش بزرگ است و می‌خواهد برنامه‌ای بنویسد که اطلاعات حیوانات را مدیریت کند.

### ساختار داده

هر حیوان با ویژگی‌های زیر تعریف می‌شود:

| ویژگی | نوع |
|---|---|
| نام (name) | `string` |
| شماره قفس (cage_number) | `int` |
| سال ورود به باغ‌وحش (year_of_entry) | `int` |
| کمیاب بودن یا نبودن (is_rare) | `bool` |
| غذا خورده یا نخورده (is_fed) | `bool` |

برنامه از طریق دستورهایی که در هر خط از ورودی می‌آیند با کاربر تعامل دارد.

### دستورها

#### `SET <تعداد_قفس>`
تعداد قفس‌های باغ‌وحش را مشخص می‌کند؛ یعنی شماره‌ی قفس‌های مجاز از ۱ تا این عدد است. تضمین می‌شود این دستور دقیقاً یک‌بار و در ابتدای برنامه اجرا می‌شود.

#### `ADD <نام> <شماره_قفس> <سال_ورود> <کمیاب>`
حیوان جدیدی اضافه می‌کند. مقدار `is_fed` به‌صورت پیش‌فرض `false` است. بررسی‌ها به این ترتیب انجام و در صورت خطا چاپ می‌شود (ممکن است چند خطا هم‌زمان رخ دهد؛ ترتیب چاپ باید مطابق همین فهرست باشد):

1. اگر طول نام کمتر از ۲ حرف باشد → `Invalid name`
2. اگر شماره قفس قبلاً استفاده شده باشد → `Another animal is kept in this cage`
3. اگر شماره قفس خارج از بازه مجاز باشد → `This cage does not exist`
4. اگر خطایی رخ نداده باشد → `The animal named [name] was added successfully`

#### `SEARCH name <نام>` یا `SEARCH cage_number <شماره>`
جست‌وجوی حیوانات بر اساس نام (می‌تواند چند نتیجه داشته باشد، به ترتیب افزوده‌شدن یا آخرین مرتب‌سازی) یا بر اساس شماره قفس (حداکثر یک نتیجه). در صورت نبود نتیجه → `No animal was found`.

#### `LIST`
نمایش اطلاعات همه‌ی حیوانات، به همان ترتیب فعلی لیست. در صورت خالی بودن → `No animal was found`.

#### `DELETE <شماره_قفس>`
حذف حیوان متناظر با شماره قفس. در صورت نبود → `No animal was found`، در غیر این صورت → `The animal named [name] was deleted successfully`.

#### `EDIT <شماره_قفس> <فیلد> [مقدار جدید]`
ویرایش یکی از فیلدهای `name`، `year_of_entry`، `is_rare`، `is_fed` برای حیوان متناظر با شماره قفس. برای دو فیلد بولی (`is_rare`, `is_fed`) نیازی به وارد کردن مقدار نیست چون فقط معکوس می‌شود. در صورت نبود حیوان → `No animal was found`. اگر فیلد ویرایش‌شده `name` باشد و نام جدید کمتر از ۲ حرف باشد → `Invalid name`؛ در غیر این صورت پس از هر ویرایش موفق → `The animal named [name] was edited successfully` (نام قبل از ویرایش).

#### `SORT`
مرتب‌سازی صعودی حیوانات، ابتدا بر اساس نام (الفبایی) و در صورت تساوی نام، بر اساس شماره قفس. این دستور خروجی ندارد.

#### `FEED <تعداد>`
تغذیه‌ی حیوانات گرسنه (`is_fed == false`)، با اولویت:

1. حیوانات کمیاب مقدم بر غیرکمیاب‌اند.
2. در صورت تساوی کمیاب بودن، حیوان با سال ورود کمتر مقدم است.
3. در صورت تساوی هر دو، ترتیب فعلی لیست حفظ می‌شود.

اگر تعداد وارد شده بیشتر از تعداد حیوانات گرسنه باشد، فقط همان‌ها تغذیه می‌شوند. به ازای هر حیوان تغذیه‌شده → `The animal named [name] was fed`.

> **نکته پیاده‌سازی (پیشنهادی در صورت تمرین):** برای FEED باید از یک بردار از **اشاره‌گر به حیوان** (نه کپی حیوان) استفاده شود تا تغییر `is_fed` روی خودِ داده‌های اصلی اعمال شود؛ سپس این بردار بر اساس اولویت‌های بالا مرتب و به‌اندازه‌ی `min(تعداد گرسنه‌ها, آرگومان ورودی)` پیمایش می‌شود.

#### `EXIT`
پایان اجرای برنامه.

### ورودی و خروجی
- ورودی: در هر خط یک دستور به‌همراه آرگومان‌های آن.
- خروجی: برای هر دستور، طبق توضیحات، در صورت نیاز یک یا چند خط چاپ می‌شود.

### مثال (گام یک)

**ورودی:**
```
SET 100
ADD zebra 80 1700 1
ADD elephant 60 1800 0
ADD penguin 110 2000 1
ADD elephant 45 1890 0
ADD a -5 1950 0
ADD giraffe 45 1900 0
SEARCH name elephant
SEARCH cage_number 80
LIST
DELETE 60
LIST
EDIT 80 name tiger
SEARCH cage_number 80
EDIT 80 is_rare
SEARCH cage_number 80
SORT
LIST
EDIT 80 name buffalo
SORT
LIST
EDIT 45 name buffalo
SORT
LIST
DELETE 90
FEED 1
ADD monkey 10 1900 1
FEED 1
FEED 2
EXIT
```

**خروجی:**
```
The animal named zebra was added successfully
The animal named elephant was added successfully
This cage does not exist
The animal named elephant was added successfully
Invalid name
This cage does not exist
Another animal is kept in this cage
elephant 60 1800 0
elephant 45 1890 0
zebra 80 1700 1
zebra 80 1700 1
elephant 60 1800 0
elephant 45 1890 0
The animal named elephant was deleted successfully
zebra 80 1700 1
elephant 45 1890 0
The animal named zebra was edited successfully
tiger 80 1700 1
The animal named tiger was edited successfully
tiger 80 1700 0
elephant 45 1890 0
tiger 80 1700 0
The animal named tiger was edited successfully
buffalo 80 1700 0
elephant 45 1890 0
The animal named elephant was edited successfully
buffalo 45 1890 0
buffalo 80 1700 0
No animal was found
The animal named buffalo was fed
The animal named monkey was added successfully
The animal named monkey was fed
The animal named buffalo was fed
```

### راهنمای تست‌ها (گام یک)

| تست‌ها | دستورهای بررسی‌شده |
|---|---|
| ۱ تا ۱۳ | `SET`، `ADD`، `LIST`، `EXIT` |
| ۱۴ تا ۲۱ | موارد قبل + `SEARCH` |
| ۲۲ تا ۲۵ | موارد قبل + `DELETE` |
| ۲۶ تا ۲۹ | موارد قبل + `EDIT` |
| ۳۰ تا ۳۱ | موارد قبل + `SORT` |
| ۳۲ تا ۴۰ | موارد قبل + `FEED` (جامع) |

---

## گام دو — ذخیره‌سازی و بازیابی روی فایل

> ⚠️ این بخش ادامه‌ی گام یک است و باید ابتدا گام یک حل شده باشد. بر خلاف گام یک، این بخش توسط داور خودکار تصحیح نمی‌شود و به‌صورت دستی بررسی می‌شود.

با افزایش تعداد حیوانات، امین متوجه می‌شود نگه‌داشتن اطلاعات فقط در حافظه (تا زمانی که برنامه اجراست) کافی نیست؛ پس دو دستور جدید برای ذخیره و بازیابی اطلاعات از فایل متنی اضافه می‌شود.

#### `SAVE <نام_فایل>`
تمام اطلاعات حیوانات را در فایل متنی داده‌شده ذخیره می‌کند و در یک خط چاپ می‌کند: `Animals were saved successfully`.
فرمت دقیق خطوط فایل بر عهده‌ی برنامه‌نویس است، اما باید امکان بازیابی کامل اطلاعات را فراهم کند. رویکرد پیشنهادی: در خط اول فایل، تعداد کل حیوانات نوشته شود و سپس در هر خط، به ازای هر حیوان: نام، شماره قفس، سال ورود، کمیاب بودن و غذا خورده بودن.

#### `LOAD <نام_فایل>`
اطلاعات را از فایل متنی خوانده و **به لیست فعلی اضافه می‌کند** (نه جایگزین).
- اگر فایل وجود نداشته باشد → `The file does not exist`
- در غیر این صورت → `Animals were loaded successfully`

تضمین می‌شود فایلی که با موفقیت لود می‌شود، قبلاً توسط همین برنامه (دستور `SAVE`) نوشته شده و هیچ تداخل شماره قفسی رخ نمی‌دهد.

### مثال‌ها (گام دو)

**ورودی نمونه ۱** (فرض: فایل `animals.txt` از قبل با محتوای زیر موجود است)
```
LOAD animals.txt
SET 100
ADD zebra 80 1700 1
ADD elephant 60 1800 0
ADD elephant 45 1890 0
ADD giraffe 45 1900 0
SEARCH name elephant
LIST
DELETE 60
LIST
EDIT 80 name tiger
SEARCH cage_number 80
SORT
LIST
FEED 1
SAVE animals.txt
ADD elephant 65 1800 0
EXIT
```

**خروجی نمونه ۱:**
```
The animal named zebra was added successfully
The animal named elephant was added successfully
The animal named elephant was added successfully
Another animal is kept in this cage
elephant 60 1800 0
elephant 45 1890 0
zebra 80 1700 1
elephant 60 1800 0
elephant 45 1890 0
The animal named elephant was deleted successfully
zebra 80 1700 1
elephant 45 1890 0
The animal named zebra was edited successfully
tiger 80 1700 1
elephant 45 1890 0
tiger 80 1700 1
The animal named tiger was fed
Animals were saved successfully
The animal named elephant was added successfully
```

**ورودی نمونه ۲** (اجرای بعدی برنامه؛ فایل `animals.txt` بر اساس ذخیره‌سازی قبلی موجود است):
```
SET 200
LOAD animal.txt
LOAD animals.txt
LIST
ADD Camel 62 1860 0
LIST
EDIT 80 is_fed
FEED 2
EXIT
```

**خروجی نمونه ۲:**
```
The file does not exist
Animals were loaded successfully
elephant 45 1890 0
tiger 80 1700 1
The animal named Camel was added successfully
elephant 45 1890 0
tiger 80 1700 1
Camel 62 1860 0
The animal named tiger was edited successfully
The animal named tiger was fed
The animal named Camel was fed
```

---

## ورودی و خروجی (کلی)

- **ورودی:** در هر خط، یک دستور به‌همراه آرگومان‌های احتمالی آن.
- **خروجی:** به ازای هر دستور، در صورت نیاز، در یک یا چند خط چاپ می‌شود.
