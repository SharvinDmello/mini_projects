from PIL import Image
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
import os

def images_to_pdf(folder_path, pdf_path, pdf_name):
    files = os.listdir(folder_path)
    # Filter only image files .jpg and .png
    image_files = [f for f in files if f.endswith(('.jpg', '.png'))]
    # Create a new PDF file
    pdf_file_path = os.path.join(pdf_path, f"{pdf_name}.pdf")
    c = canvas.Canvas(pdf_file_path, pagesize=letter)
    # Add each image to the PDF
    for image_name in image_files:
        image_path = os.path.join(folder_path, image_name)
        img = Image.open(image_path)
        img_width, img_height = img.size
        aspect_ratio = img_height / img_width
        # Set the image size to fit the page width
        width = letter[0] - 40  # 40 units margin
        height = width * aspect_ratio
        # Add the image to the PDF
        c.drawImage(image_path, 20, 20, width, height)
        c.showPage()
    c.save()
    print(f"PDF saved at {pdf_file_path}")
folder_path = "C:\disc D\my_python\images"
pdf_path = "C:\disc D\my_python\images"
pdf_name = "DEVELOPMENT OF LATERAL SURFACES"

images_to_pdf(folder_path, pdf_path, pdf_name)
