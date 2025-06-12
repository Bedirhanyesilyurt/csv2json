# 🔄 csv2json — Convert CSV to JSON in C

This project is a simple CSV-to-JSON converter written in C. It takes a `.csv` file and outputs a `.json` file using a command-line interface. You can choose whether your CSV contains column headers or not by passing the `header=ON` or `header=OFF` flag.

Bu proje, C dili ile yazılmış basit bir CSV'den JSON'a dönüştürücü programdır. Komut satırından `.csv` dosyasını `.json` dosyasına çevirir. CSV dosyasında kolon başlıkları olup olmadığını belirtmek için `header=ON` veya `header=OFF` parametresi kullanılır.

---

## 🧠 Features / Özellikler

- ✅ Converts `.csv` to `.json`
- ✅ Supports CSVs **with** or **without headers**
- ✅ Simple command-line interface
- ✅ Written in pure C

---

## 🚀 Usage / Kullanım

### Command Line Syntax / Komut Satırı Söz Dizimi

```bash
csv2json.exe input.csv output.json header=ON


Parameters / Parametreler
input.csv: Input file name (giriş CSV dosyası)

output.json: Output file name (çıkış JSON dosyası)

header=ON: CSV has column headers (kolon başlıkları var)

header=OFF: CSV has no headers (kolon başlıkları yok)


🛠️ Build Instructions / Derleme Talimatları
gcc csv2json.c -o csv2json.exe


💾 Output Format / Çıktı Formatı
If header=ON:
{
	{
		"Column1": "Value1",
		"Column2": "Value2"
	},
	{
		"Column1": "Value3",
		"Column2": "Value4"
	}
}

If header=OFF:
{
  satir 1 
	{
		"kolon 1": "Value1",
		"kolon 2": "Value2"
	},
  satir 2 
	{
		"kolon 1": "Value3",
		"kolon 2": "Value4"
	}
}
