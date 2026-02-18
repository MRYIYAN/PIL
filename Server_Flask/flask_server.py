from flask

#=======================================================#
#                   IMPORTS                             #
#=======================================================# 
import Flask, render_template, request, jsonify
import subprocess
import os 
import json


app = Flask(__name__)


@app.route("/Docker", methods=["POST"])

def Docker():

    data = request.get_json(silent=True)
    if not data:
        return jsonify({"ok": False, "error": "No se ha recibido una orden"})
    
    try: 
        with open("Docker/datos.json",) as f:
            datos = json.load(f)
    except Exception as e:
        return jsonify({"ok": False, "error": f"Error al leer el archivo de datos: {str(e)}"})
    
    try: 
        payload = json.dumps(data)

        proc = subrocess.Popen(

            ["docker", "exec", "-i", "compilador C", "python3", "/compilador_C/compilador.py"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text= True 
        )
        stdout, stderr = proc.comunicate(input=payload)

        if proc.returncode != 0: 
            return jsonify({

                "ok": False,
                "error": f"Error al ejecutar el conted de compilador C: {stderr}"
                "stderr": stderr
                "stdout": stdout

            }), 500

        if not stdout.strip():
            return jsonify({
                "ok": False,
                "error": "No se ha recibido una respuesta del contenedor de compilador C"
            })
        try:
            response_data = json.loads(stdout)
        except json.JSONDecodeError as e:
            return jsonify({
                "ok": False,
                "error": f"Error al decodificar la respuesta del contenedor de compilador C: {str(e)}",
                "stdout": stdout,
                "stderr": stderr
            }), 500