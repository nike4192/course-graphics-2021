# Методичка (типа)

## Задание 6

### Web

#### Анотация
Все что нужно сделать по сути - заполнить буфер вершин.\
Я говорил с преподователем, по поводу, можно ли использовать WebGL, он сказал что не против.\
Так же и по поводу библиотеки three.js, но в ней можно создавать свои [шейдеры](https://threejs.org/docs/index.html?q=shader#api/en/materials/RawShaderMaterial) и писать на более низком уровне, оперируя буферами и изменениме атрибутов.

#### Стек:

- JavaScript, который похож на C# чуть более, чем на половину
- [WebGL](https://ru.wikipedia.org/wiki/WebGL), основан на [OpenGL ES](https://ru.wikipedia.org/wiki/OpenGL_ES), который в свою очередь является подмножеством [OpenGL](https://ru.wikipedia.org/wiki/OpenGL)

#### Содержание:

`index.three.html` - [Ссылка](https://coor.xyz/course-graphics-2021/web/index.three.html) на пример. Основан на библиотеке [three.js](https://threejs.org/), она удобная и не нужно писать велосипеды, заморачиваться с созданием/прикреплением/заполнением буферов WebGL - более простой вариант, половина объектов готова, место для написания кода помечен комментариями
```js
// USER CODE N [START|END]
```
Все что помечено комментариями в последствии стоит удалить.\
Да и вообще по хорошему переструктурировать код, чтобы не было под одну копирку:
- убрать свет
- `GUI` может быть
- `controls` заменить на изменение `position`, `rotation` `mesh` объектов

`index.webgl.html` - [Ссылка](https://coor.xyz/course-graphics-2021/web/index.webgl.html) на пример. скопирован [отсюда](https://webglfundamentals.org/webgl/lessons/webgl-3d-orthographic.html), здесь исползуется чистый WebGL, самописные утилиты (матрицы преобразований, настройка инпутов и пр.). Здесь все выражения начинающиес `gl...` подразумевают под собой те же функции что и в OpenGL:
- gl.viewport ~ [glViewport](https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glViewport.xhtml)
- gl.clear ~ [glClear](https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glClear.xhtml)
- gl.enable ~ [glEnable](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glEnable.xml)
- и т.д.

То есть можно легко перейти с JS на C# или кому как удобно, только на JS не нужно заморачиваться с окнами (их инициализацией/созданием/обработкой событий с устройств ввода.)

### C++

#### Анотация

Руководствовался этим [сайтом](https://learnopengl.com/). Уже забыл как скачивал все эти библиотке в `lib`, поэтому просто залил эти ~144Мб.\
По сути я просто скопировал three.js, просто потому, что уже давно знаком и смотрел их код.\
В этом примере есть всякие объекты, даже [торический узел](https://en.wikipedia.org/wiki/Torus_knot).\
Но на нем писать сложно, хотя бы потому что компилируется долго и не знаю CMake.\
В целом плохой код, я даже не замарочился над рендерингом фигур по отдельности.

#### Стек

- очевидно C++, но местами я даже не знаю где C
- [GLFW](https://www.glfw.org/) - API для оконных приложений с контекстом, событиями и пр. Скачивал вроде прямо с сайта, не сложно
- [glad](https://github.com/Dav1dde/glad) - предоставляет функции для определенных версий OpenGL, по моему с помощью `pip` скачивал
- [glm](https://glm.g-truc.net/0.9.9/index.html) - математика для OpenGL, с самого сайта скачивал
- [std](https://github.com/nothings/stb) - для текстур, просто скачал `stb_image.h` файл, он лежит в `src`
- [CMake](cmake.org) - единственный с кем я долго возился и так и не разобрался, компилирует проект

## Задание 7

Создание сложного графического объекта (средствами OPENGL)

### Предложения

Можно с помощью редактора (блендер, 3DM и пр.) создать объект и отрендерить с помощью three.js.
У него есть всякие загрузчики: 3DMLoader, GLTFLoader, KTX2Loader, MTLLoader, OBJLoader и [прочее](https://threejs.org/docs/index.html?q=loader) и куча [примеров](https://threejs.org/examples/?q=loader) как их использовать.\
Или же с помощью примитивов: Box, Sphere сделать какое-нибудь архитектурное сооружение, тем боле можно с материалами поиграться и наложить текстуру.\

## Задание 8

Алгоритм обратной трассировки лучей (ЯП)

### Предложения

Сам я никогда еще не писал Raymarching/Raytrace, но видел [видео](https://www.youtube.com/watch?v=9g8CdctxmeU) (без звука) и есть много [примеров](https://www.shadertoy.com/results?query=raymarching) как можно сделать.
Чтобы запустить это на WebGl можно, отдать на рендеринг прямоугольник от -1 до 1 по осям x и y, а весь код заключается во фрагментном шейдере
Можно этим кодом воспользоваться https://webglfundamentals.org/webgl/webgl-2d-rectangle-top-left.html.
Из первой главы [Webgl Fundamentals](https://webglfundamentals.org/webgl/lessons/webgl-fundamentals.html).