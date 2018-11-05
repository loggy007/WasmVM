# 設計理念

現在 WebAssembly 主要是在網頁瀏覽器，協助 JavaScript 用比較貼近機器底層的方式處理運算的部份
既然是"協助" JavaScript， 所以你要跑WebAssembly , 就算不透過瀏覽器，還是需要 JavaScript 的幫忙
我覺得 WebAssembly 做為完整的組合語言，在瀏覽器以外的地方應該不需要 JavaScript 就能自己跑，而且應該能做到瀏覽器和桌面能共用同一份程式檔
想像一下未來你可能可以把一個.wasm檔直接點兩下打開會動，放到網站上大家用瀏覽器看也會動，不用再特別寫成網站，甚至感覺上根本沒有網站/桌面的分隔

要在桌面上執行有個問題:
一般的桌面程式直接就是機器能看的懂的機器碼
但是 WebAssembly 對機器來說根本看不懂，就像有人和你說印度話，你完全黃人問號 :thinking: 
所以我們需要一個師爺來翻譯翻譯
師爺有很多種，一種是即時口譯，說一句翻一句做一句，在高階語言是直譯器，組合語言叫做虛擬機器
一種是說的時候先記錄在紙上，再叫別人去做，在高階語言叫做編譯器，組合語言叫做組譯器(edited)
還有一種師爺是記錄在腦海裡，記錄完自己馬上去做
這個叫做即時編譯器(Just-in-time compiler, 簡稱 JIT compiler)

WasmVM最主要的工作就是當那個師爺，而且我們有兩個師爺，平常先叫虛擬機器做事，但是即時編譯器同時也在編譯
等即時編譯器編完，這段程式如果再重複被使用，就不用翻譯，直接跑翻完的就好

另外，為了要在桌面跑，我們還必須設計 SysCall 的機制 ，透過 SysCall 來做到 WebAssembly 管不到的系統操作，這些在瀏覽器是用 JavaScript 解決，我們得自己幹
所以 WasmVM 不只能執行 WebAssembly，我們還會定義一套完整又輕巧的架構，這也是 WasmVM 最重要的價值