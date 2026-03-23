from setuptools import setup, find_packages
import os
import pathlib

module_path = os.path.join('pyavevae3dext', 'AiAvevaPythonInterface.pyd')
print(module_path)

setup(
    name='pyavevae3dext',
    version='0.1.0',
    description='Python Package Allows to interact with AVEVA Unified Engineering 3.0 using AVEVA Embedded Python Interaction dll (64-bit).',
    long_description=pathlib.Path("README.md").read_text(),
    long_description_content_type="text/markdown",
    url="https://github.com/shivangKheradiya/AiAvevaPythonInterface",
    author="Shivang Kheradiya",
    author_email="shivangatul@gmail.com",
    license="MIT license",
    project_urls={
        "Documentation": "https://github.com/shivangKheradiya/AiAvevaPythonInterface",
        "Source":"https://github.com/shivangKheradiya/AiAvevaPythonInterface",
    },
    classifiers=[
        "Programming Language :: Python :: 3.10",
        "Programming Language :: Python :: 3.13",
        "Programming Language :: Python :: Implementation :: CPython",
        "Topic :: Software Development :: Libraries",
        "Topic :: Utilities",
    ],
    python_requires=">=3.10",
    packages=find_packages(),
    include_package_data=True,
    package_data={
        'pyavevae3dext': [module_path],
    },
    zip_safe=False,
)
